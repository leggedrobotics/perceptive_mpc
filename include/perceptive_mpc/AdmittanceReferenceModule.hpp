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

// msgs
#include <geometry_msgs/Wrench.h>
#include <nav_msgs/Path.h>
#include <ros/ros.h>
#include <Eigen/Eigen>
#include <kindr/Core>
#include <mutex>
#include <string>

namespace perceptive_mpc {

class AdmittanceReferenceModule {
 public:
  AdmittanceReferenceModule();

  bool initialize();

  using eigen_pose_t = Eigen::Matrix<double, -1, 1>;
  using eigen_pose_vector_t = std::vector<eigen_pose_t, Eigen::aligned_allocator<eigen_pose_t>>;

  nav_msgs::Path adaptPath(double dt, const nav_msgs::Path& rawPath, const kindr::WrenchD measuredWrench);

  // interface for Kinematic Simulation demo implementation that does not use nav_msgs::Path types
  void adaptPath(double dt, eigen_pose_vector_t& path, const kindr::WrenchD measuredWrench);

  void setDesiredEndeffectorWrench(const geometry_msgs::Wrench::ConstPtr&);

 protected:
  kindr::WrenchD desiredEEWrench_;
  std::mutex desiredEEWrenchMutex_;

  Eigen::Vector3d forcePGains_;
  Eigen::Vector3d torquePGains_;
  Eigen::Vector3d forceIGains_;
  Eigen::Vector3d torqueIGains_;

  kindr::WrenchD wrenchIntegralMax_;
  kindr::WrenchD wrenchIntegral_;

  void antiWindup();
};

}  // namespace perceptive_mpc
