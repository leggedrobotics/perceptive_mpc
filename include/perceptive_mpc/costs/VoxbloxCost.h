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

#pragma once

#include <ocs2_core/automatic_differentiation/CppAdInterface.h>

#include <perceptive_mpc/costs/PointsOnRobot.h>

#include "ocs2_core/cost/CostFunctionBase.h"
#include "perceptive_mpc/Definitions.h"

namespace voxblox {
class EsdfCachingVoxel;

template <typename VoxelType>
class Interpolator;
}  // namespace voxblox

namespace perceptive_mpc {
using typename voxblox::EsdfCachingVoxel;
using voxblox::Interpolator;

struct VoxbloxCostConfig {
  double mu = 1;
  double delta = 1e-3;
  double maxDistance = 2.0;
  std::shared_ptr<const PointsOnRobot> pointsOnRobot;
  std::shared_ptr<Interpolator<EsdfCachingVoxel>> interpolator;
};

class VoxbloxCost : public ocs2::CostFunctionBase<Definitions::STATE_DIM_, Definitions::INPUT_DIM_> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  using Ptr = std::shared_ptr<VoxbloxCost>;
  using ConstPtr = std::shared_ptr<const VoxbloxCost>;

  using BASE = CostFunctionBase<Definitions::STATE_DIM_, Definitions::INPUT_DIM_>;
  using typename BASE::input_vector_t;
  using typename BASE::scalar_t;
  using typename BASE::state_matrix_t;
  using typename BASE::state_vector_t;

  VoxbloxCost(const VoxbloxCostConfig& config)
      : CostFunctionBase(),
        interpolator_(config.interpolator),
        maxDistance_(config.maxDistance),
        mu_(config.mu),
        delta_(config.delta),
        pointsOnRobot_(config.pointsOnRobot),
        distances_(pointsOnRobot_->numOfPoints()),
        gradientsVoxblox_(pointsOnRobot_->numOfPoints(), pointsOnRobot_->numOfPoints() * 3),
        gradients_(pointsOnRobot_->numOfPoints(), 13) {}

  VoxbloxCost(const VoxbloxCost& rhs)
      : CostFunctionBase(),
        interpolator_(rhs.interpolator_),
        maxDistance_(rhs.maxDistance_),
        mu_(rhs.mu_),
        delta_(rhs.delta_),
        pointsOnRobot_(new PointsOnRobot(*rhs.pointsOnRobot_)),
        distances_(rhs.distances_),
        gradientsVoxblox_(rhs.gradientsVoxblox_),
        gradients_(rhs.gradients_) {}

  /**
   * Destructor
   */
  ~VoxbloxCost() override = default;

  VoxbloxCost* clone() const override { return new VoxbloxCost(*this); }

  void setCurrentStateAndControl(const scalar_t& t, const state_vector_t& x, const input_vector_t& u);

  void getIntermediateCost(scalar_t& L) override;
  void getIntermediateCostDerivativeState(state_vector_t& dLdx) override;
  void getIntermediateCostSecondDerivativeState(state_matrix_t& dLdxx) override;
  void getIntermediateCostDerivativeInput(input_vector_t& dLdu) override;
  void getIntermediateCostSecondDerivativeInput(input_matrix_t& dLduu) override;
  void getIntermediateCostDerivativeInputState(input_state_matrix_t& dLdux) override;
  void getTerminalCost(scalar_t& Phi) override;
  void getTerminalCostDerivativeState(state_vector_t& dPhidx) override;
  void getTerminalCostSecondDerivativeState(state_matrix_t& dPhidxx) override;
  void getIntermediateCostDerivativeTime(scalar_t& dLdt) override;
  void getTerminalCostDerivativeTime(scalar_t& dPhidt) override;

  void getIntermediateCostDerivativeStateVerbose(state_vector_t& dLdx);

 private:
  scalar_t mu_;
  scalar_t delta_;
  scalar_t maxDistance_;

  std::shared_ptr<const PointsOnRobot> pointsOnRobot_;
  std::shared_ptr<Interpolator<EsdfCachingVoxel>> interpolator_;

  Eigen::Matrix<scalar_t, -1, 1> distances_;
  Eigen::MatrixXd gradientsVoxblox_;
  Eigen::Matrix<scalar_t, -1, STATE_DIM_> gradients_;

  scalar_t getPenaltyFunctionValue(scalar_t h) const {
    if (h > delta_) {
      return -mu_ * log(h);
    } else {
      return mu_ * (-log(delta_) + scalar_t(0.5) * pow((h - 2.0 * delta_) / delta_, 2.0) - scalar_t(0.5));
    };
  };

  scalar_t getPenaltyFunctionDerivative(scalar_t h) const {
    if (h > delta_) {
      return -mu_ / h;
    } else {
      return mu_ * ((h - 2.0 * delta_) / (delta_ * delta_));
    };
  };

  scalar_t getPenaltyFunctionSecondDerivative(scalar_t h) const {
    if (h > delta_) {
      return mu_ / (h * h);
    } else {
      return mu_ / (delta_ * delta_);
    };
  };
};
}  // namespace perceptive_mpc