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
#include <perceptive_mpc/costs/QuadraticEndeffectorTrackingCost.h>
#include <perceptive_mpc/costs/InterpolatePoseTrajectory.h>

using namespace perceptive_mpc;

QuadraticEndeffectorTrackingCost* QuadraticEndeffectorTrackingCost::clone() const {
  return new QuadraticEndeffectorTrackingCost(*this);
}

void QuadraticEndeffectorTrackingCost::intermediateCostFunction(ad_scalar_t time, const ad_dynamic_vector_t& state,
                                                                const ad_dynamic_vector_t& input, const ad_dynamic_vector_t& parameters,
                                                                ad_intermediate_cost_vector_t& costValues) const {
  const Eigen::Quaternion<ad_scalar_t> desiredOrientation(parameters.head<4>());
  const Eigen::Matrix<ad_scalar_t, 3, 1>& desiredPosition = parameters.tail<3>();

  Eigen::Matrix<ad_scalar_t, 4, 4> currentEEPose;
  kinematics_->computeState2EndeffectorTransform(currentEEPose, state);

  const Eigen::Matrix<ad_scalar_t, 3, 3>& currentOrientation = currentEEPose.topLeftCorner<3, 3>();
  const Eigen::Matrix<ad_scalar_t, 3, 1>& currentPosition = currentEEPose.topRightCorner<3, 1>();

  Eigen::Matrix<ad_scalar_t, 3, 1> positionError = desiredPosition - currentPosition;
  Eigen::Quaternion<ad_scalar_t> currentOrientationQuat = matrixToQuaternion(currentOrientation);
  Eigen::Matrix<ad_scalar_t, 3, 1> orientationError = ocs2::quaternionDistance(currentOrientationQuat, desiredOrientation);

  Eigen::Matrix<ad_scalar_t, 6, 1> error;
  error << positionError, orientationError;

  costValues = ad_intermediate_cost_vector_t();
  costValues << R_.array().sqrt().matrix().cast<ad_scalar_t>() * input, eePoseQ_.array().sqrt().matrix().cast<ad_scalar_t>() * error;
}

void QuadraticEndeffectorTrackingCost::terminalCostFunction(ad_interface_t::ad_scalar_t time,
                                                            const ad_interface_t::ad_dynamic_vector_t& state,
                                                            const ad_interface_t::ad_dynamic_vector_t& parameters,
                                                            ad_terminal_cost_vector_t& costValues) const {
  const Eigen::Quaternion<ad_scalar_t> desiredOrientation(parameters.head<4>());
  const Eigen::Matrix<ad_scalar_t, 3, 1>& desiredPosition = parameters.tail<3>();

  Eigen::Matrix<ad_scalar_t, 4, 4> currentEEPose;
  kinematics_->computeState2EndeffectorTransform(currentEEPose, state);

  const Eigen::Matrix<ad_scalar_t, 3, 3>& currentOrientation = currentEEPose.topLeftCorner<3, 3>();
  const Eigen::Matrix<ad_scalar_t, 3, 1>& currentPosition = currentEEPose.topRightCorner<3, 1>();

  Eigen::Matrix<ad_scalar_t, 3, 1> positionError = desiredPosition - currentPosition;
  Eigen::Quaternion<ad_scalar_t> currentOrientationQuat = matrixToQuaternion(currentOrientation);
  Eigen::Matrix<ad_scalar_t, 3, 1> orientationError = ocs2::quaternionDistance(currentOrientationQuat, desiredOrientation);

  Eigen::Matrix<ad_scalar_t, 6, 1> error;
  error << positionError, orientationError;

  costValues = ad_terminal_cost_vector_t();
  costValues = eePoseQFinal_.array().sqrt().matrix().cast<ad_scalar_t>() * error;
}

QuadraticEndeffectorTrackingCost::dynamic_vector_t QuadraticEndeffectorTrackingCost::getIntermediateParameters(
    QuadraticEndeffectorTrackingCost::scalar_t time) const {
  return interpolateReference(time);
}
size_t QuadraticEndeffectorTrackingCost::getNumIntermediateParameters() const {
  return Definitions::POSE_DIM;
}

QuadraticEndeffectorTrackingCost::dynamic_vector_t QuadraticEndeffectorTrackingCost::getTerminalParameters(scalar_t time) const {
  return interpolateReference(time);
}
size_t QuadraticEndeffectorTrackingCost::getNumTerminalParameters() const {
  return Definitions::POSE_DIM;
}

QuadraticEndeffectorTrackingCost::dynamic_vector_t QuadraticEndeffectorTrackingCost::interpolateReference(
    QuadraticEndeffectorTrackingCost::scalar_t time) const {
  const auto& desiredTimeTrajectory = costDesiredTrajectoriesPtr_->desiredTimeTrajectory();
  const auto& desiredStateTrajectory = costDesiredTrajectoriesPtr_->desiredStateTrajectory();
  return interpolatePoseTrajectory(desiredTimeTrajectory, desiredStateTrajectory, time);
}

Eigen::Quaternion<QuadraticEndeffectorTrackingCost::ad_scalar_t> QuadraticEndeffectorTrackingCost::matrixToQuaternion(
    const Eigen::Matrix<ad_scalar_t, 3, 3>& R) const {
  ad_scalar_t t1, t2, t;
  ad_scalar_t x1, x2, x;
  ad_scalar_t y1, y2, y;
  ad_scalar_t z1, z2, z;
  ad_scalar_t w1, w2, w;

  t1 = CppAD::CondExpGt(R(0, 0), R(1, 1), 1 + R(0, 0) - R(1, 1) - R(2, 2), 1 - R(0, 0) + R(1, 1) - R(2, 2));
  t2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), 1 - R(0, 0) - R(1, 1) + R(2, 2), 1 + R(0, 0) + R(1, 1) + R(2, 2));
  t = CppAD::CondExpLt(R(2, 2), ad_scalar_t(0.0), t1, t2);

  x1 = CppAD::CondExpGt(R(0, 0), R(1, 1), t, R(1, 0) + R(0, 1));
  x2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(0, 2) + R(2, 0), R(2, 1) - R(1, 2));
  x = CppAD::CondExpLt(R(2, 2), ad_scalar_t(0.0), x1, x2);

  y1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(1, 0) + R(0, 1), t);
  y2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(2, 1) + R(1, 2), R(0, 2) - R(2, 0));
  y = CppAD::CondExpLt(R(2, 2), ad_scalar_t(0.0), y1, y2);

  z1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(0, 2) + R(2, 0), R(2, 1) + R(1, 2));
  z2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), t, R(1, 0) - R(0, 1));
  z = CppAD::CondExpLt(R(2, 2), ad_scalar_t(0.0), z1, z2);

  w1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(2, 1) - R(1, 2), R(0, 2) - R(2, 0));
  w2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(1, 0) - R(0, 1), t);
  w = CppAD::CondExpLt(R(2, 2), ad_scalar_t(0.0), w1, w2);

  Eigen::Matrix<ad_scalar_t, 4, 1> q({x, y, z, w});
  q *= 0.5 / sqrt(t);

  Eigen::Quaternion<ad_scalar_t> quaternion;
  quaternion.x() = q(0);
  quaternion.y() = q(1);
  quaternion.z() = q(2);
  quaternion.w() = q(3);

  return quaternion;
}
