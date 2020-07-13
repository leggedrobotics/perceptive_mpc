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

#include <visualization_msgs/MarkerArray.h>

#include <Eigen/Core>
#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>

#include "perceptive_mpc/Definitions.h"

namespace ocs2 {
template <typename SCALAR_T>
class CppAdInterface;
}

namespace perceptive_mpc {

struct PointsOnRobotConfig {
  using points_radii_t = std::vector<std::vector<std::pair<double, double>>>;
  points_radii_t pointsAndRadii;
  std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics;
};

class PointsOnRobot {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  using points_radii_t = std::vector<std::vector<std::pair<double, double>>>;

  explicit PointsOnRobot(const PointsOnRobotConfig& config);

  PointsOnRobot(const PointsOnRobot& rhs);

  void initialize(const std::string& modelName, const std::string& modelFolder = "/tmp/ocs2", bool recompileLibraries = true,
                  bool verbose = true);

  Eigen::VectorXd getPoints(const Eigen::VectorXd& state) const;

  Eigen::MatrixXd getJacobian(const Eigen::VectorXd& state) const;

  Eigen::VectorXd getRadii() const;

  int numOfPoints() const;

  visualization_msgs::MarkerArray getVisualization(const Eigen::VectorXd& state) const;

 private:
  void setADInterfaces(const std::string& modelName, const std::string& modelFolder);
  void createModels(bool verbose);
  void loadModelsIfAvailable(bool verbose);

  std::shared_ptr<ocs2::CppAdInterface<double>> cppAdInterface_;
  std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics_;

  std::vector<std::vector<double>> points_;
  Eigen::VectorXd radii_;
};
}  // namespace perceptive_mpc