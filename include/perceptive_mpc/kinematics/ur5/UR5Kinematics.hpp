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

#include <Eigen/Core>
#include <cppad/cg.hpp>

#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>
#include "cppad/cg/math.hpp"

namespace perceptive_mpc {

template <typename SCALAR_T>
class UR5Kinematics : public KinematicsInterface<SCALAR_T> {
 public:
  std::string armMountLinkName() const override { return "base"; }
  std::string toolMountLinkName() const override { return "wrist_3_link"; }

 protected:
  Eigen::Matrix<SCALAR_T, 4, 4> computeArmMountToToolMountTransform(const Eigen::Matrix<SCALAR_T, 6, 1>& armState) const override;

  Eigen::Matrix<SCALAR_T, 3, -1> computeArmState2MultiplePointsOnRobot(
      const Eigen::Matrix<SCALAR_T, 6, 1>& state, const std::vector<std::vector<double>>& points,
      const Eigen::Matrix4d& transformBase_X_ArmBase = Eigen::Matrix4d::Identity(),
      const Eigen::Matrix4d& transformToolMount_X_Endeffector = Eigen::Matrix4d::Identity(),
      const Eigen::Matrix<SCALAR_T, 4, 4>& transformWorld_X_Base = Eigen::Matrix<SCALAR_T, 4, 4>::Identity()) const override;
};

extern template class UR5Kinematics<double>;
extern template class UR5Kinematics<CppAD::AD<CppAD::cg::CG<double>>>;
}  // namespace perceptive_mpc