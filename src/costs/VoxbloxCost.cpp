/*
 * Copyright (c) 2020 Johannes Pankert <pankertj@ethz.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of this work nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <perceptive_mpc/costs/VoxbloxCost.h>
#include <voxblox/interpolator/interpolator.h>

using namespace ocs2;
using namespace perceptive_mpc;

void VoxbloxCost::setCurrentStateAndControl(const VoxbloxCost::scalar_t& t, const VoxbloxCost::state_vector_t& x,
                                            const VoxbloxCost::input_vector_t& u) {
  if (pointsOnRobot_) {
    gradientsVoxblox_.setZero();
    Eigen::VectorXd positionsPointsOnRobot = pointsOnRobot_->getPoints(x);
    Eigen::MatrixXd jacobianPointsOnRobot = pointsOnRobot_->getJacobian(x);
    Eigen::VectorXd radii = pointsOnRobot_->getRadii();
    assert(positionsPointsOnRobot.size() % 3 == 0);
    int numPoints = pointsOnRobot_->numOfPoints();
    for (int i = 0; i < numPoints; i++) {
      float distance;
      Eigen::Vector3f gradientVoxblox;
      Eigen::Ref<Eigen::Matrix<scalar_t, 3, 1>> position = positionsPointsOnRobot.segment<3>(i * 3);
      if (interpolator_->getInterpolatedDistanceGradient(position.cast<float>(), &distance, &gradientVoxblox)) {
        distances_[i] = distance - radii(i);
        gradientsVoxblox_.block<1, 3>(i, 3 * i) = gradientVoxblox.transpose().cast<double>();
      } else {
        distances_[i] = maxDistance_ - radii(i);
      }
    }
    assert(gradients_.rows() == gradientsVoxblox_.rows());
    assert(gradients_.cols() == jacobianPointsOnRobot.cols());
    gradients_ = gradientsVoxblox_ * jacobianPointsOnRobot;
  }

  BASE::setCurrentStateAndControl(t, x, u);
}

void VoxbloxCost::getIntermediateCost(VoxbloxCost::scalar_t& L) {
  L = distances_.unaryExpr([this](const auto& x) { return getPenaltyFunctionValue(x); }).sum();
}
void VoxbloxCost::getIntermediateCostDerivativeState(VoxbloxCost::state_vector_t& dLdx) {
  dLdx = gradients_.transpose() * distances_.unaryExpr([this](const auto& x) { return getPenaltyFunctionDerivative(x); });
}

void VoxbloxCost::getIntermediateCostDerivativeStateVerbose(VoxbloxCost::state_vector_t& dLdx){
  getIntermediateCostDerivativeState(dLdx);
  std::cout << "distances_: " << std::endl << distances_ << std::endl;
  std::cout << "distances penalty_derivative_: " << std::endl << distances_.unaryExpr([this](const auto& x) { return getPenaltyFunctionDerivative(x); }) << std::endl;
  std::cout << "gradients_: " << std::endl << gradients_ << std::endl;
  std::cout << "gradientsVoxblox_: " << std::endl << gradientsVoxblox_ << std::endl;
  Eigen::MatrixXd jacobianPointsOnRobot = pointsOnRobot_->getJacobian(x_);
  std::cout << "jacobianPointsOnRobot: " << std::endl << jacobianPointsOnRobot << std::endl;

}

void VoxbloxCost::getIntermediateCostSecondDerivativeState(VoxbloxCost::state_matrix_t& dLdxx) {
  dLdxx = gradients_.transpose() *
          distances_.unaryExpr([this](const auto& x) { return getPenaltyFunctionSecondDerivative(x); }).asDiagonal() * gradients_;
}
void VoxbloxCost::getIntermediateCostDerivativeInput(VoxbloxCost::input_vector_t& dLdu) {
  dLdu = input_vector_t::Zero();
}
void VoxbloxCost::getIntermediateCostSecondDerivativeInput(VoxbloxCost::input_matrix_t& dLduu) {
  dLduu = input_matrix_t::Zero();
}
void VoxbloxCost::getIntermediateCostDerivativeInputState(VoxbloxCost::input_state_matrix_t& dLdux) {
  dLdux = input_state_matrix_t::Zero();
}
void VoxbloxCost::getTerminalCost(VoxbloxCost::scalar_t& Phi) {
  Phi = 0;
}
void VoxbloxCost::getTerminalCostDerivativeState(VoxbloxCost::state_vector_t& dPhidx) {
  dPhidx = state_vector_t ::Zero();
}
void VoxbloxCost::getTerminalCostSecondDerivativeState(VoxbloxCost::state_matrix_t& dPhidxx) {
  dPhidxx = state_matrix_t ::Zero();
}
void VoxbloxCost::getIntermediateCostDerivativeTime(CostFunctionBase::scalar_t& dLdt) {
  dLdt = 0;
}
void VoxbloxCost::getTerminalCostDerivativeTime(CostFunctionBase::scalar_t& dPhidt) {
  dPhidt = 0;
}
