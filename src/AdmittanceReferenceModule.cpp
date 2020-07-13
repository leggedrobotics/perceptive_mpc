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

#include "perceptive_mpc/AdmittanceReferenceModule.hpp"
#include <geometry_msgs/PoseStamped.h>
#include <kindr_ros/kindr_ros.hpp>
#include <memory>

using namespace perceptive_mpc;

AdmittanceReferenceModule::AdmittanceReferenceModule() : desiredEEWrench_() {}

bool AdmittanceReferenceModule::initialize() {
  // load parameters
  ros::NodeHandle nh;
  const std::vector<double> torquePGains = nh.param<std::vector<double>>("admittance_gains_torque_p", std::vector<double>(3, 0));
  const std::vector<double> torqueIGains = nh.param<std::vector<double>>("admittance_gains_torque_i", std::vector<double>(3, 0));
  const std::vector<double> torqueIMax = nh.param<std::vector<double>>("admittance_gains_torque_i_max", std::vector<double>(3, 0));

  const std::vector<double> forcePGains = nh.param<std::vector<double>>("admittance_gains_force_p", std::vector<double>(3, 0));
  const std::vector<double> forceIGains = nh.param<std::vector<double>>("admittance_gains_force_i", std::vector<double>(3, 0));
  const std::vector<double> forceIMax = nh.param<std::vector<double>>("admittance_gains_force_i_max", std::vector<double>(3, 0));

  Eigen::Vector3d torqueIMaxEigen;
  Eigen::Vector3d forceIMaxEigen;

  for (int i = 0; i < 3; i++) {
    torquePGains_[i] = torquePGains[i];
    torqueIGains_[i] = torqueIGains[i];
    torqueIMaxEigen[i] = torqueIMax[i];
    forcePGains_[i] = forcePGains[i];
    forceIGains_[i] = forceIGains[i];
    forceIMaxEigen[i] = forceIMax[i];
  }

  wrenchIntegralMax_.getTorque().toImplementation() = torqueIMaxEigen;
  wrenchIntegralMax_.getForce().toImplementation() = forceIMaxEigen;
  wrenchIntegral_.setZero();

  return true;
}

nav_msgs::Path AdmittanceReferenceModule::adaptPath(double dt, const nav_msgs::Path& rawPath,
                                                    const kindr::WrenchD measuredWrench) {
  std::lock_guard<std::mutex> lockGuard(desiredEEWrenchMutex_);

  kindr::WrenchD wrenchError = measuredWrench - desiredEEWrench_;

  wrenchIntegral_ += wrenchError * dt;
  antiWindup();

  Eigen::Vector3d rotationImg = wrenchError.getTorque().toImplementation().cwiseProduct(torquePGains_) +
                                wrenchIntegral_.getTorque().toImplementation().cwiseProduct(torqueIGains_);

  kindr::RotationQuaternionD deltaRot;
  Eigen::Vector3d deltaPos;

  double r = rotationImg.norm();
  if (r > 0) {
    deltaRot.w() = std::cos(r);
    Eigen::Vector3d quatImg = std::sin(r) / r * rotationImg;
    deltaRot.x() = quatImg[0];
    deltaRot.y() = quatImg[1];
    deltaRot.z() = quatImg[2];
  }

  deltaPos = wrenchError.getForce().toImplementation().cwiseProduct(forcePGains_) +
             wrenchIntegral_.getForce().toImplementation().cwiseProduct(forceIGains_);

  nav_msgs::Path path = rawPath;

  if (path.poses.size() == 0) {
    wrenchIntegral_.setZero();
  }

  for (int i = 0; i < path.poses.size(); i++) {
    kindr::HomogeneousTransformationPosition3RotationQuaternionD pose;
    kindr_ros::convertFromRosGeometryMsg(path.poses[i].pose, pose);
    pose.getPosition().toImplementation() = pose.getPosition().toImplementation() + deltaPos;

    pose.getRotation() = deltaRot * pose.getRotation();
    kindr_ros::convertToRosGeometryMsg(pose, path.poses[i].pose);
  }

  return path;
}

void AdmittanceReferenceModule::adaptPath(double dt, eigen_pose_vector_t& path, const kindr::WrenchD measuredWrench) {
  nav_msgs::Path navPath;
  for (int i = 0; i < path.size(); i++) {
    geometry_msgs::Pose pose;
    pose.orientation.x = path[i][0];
    pose.orientation.y = path[i][1];
    pose.orientation.z = path[i][2];
    pose.orientation.w = path[i][3];
    pose.position.x = path[i][4];
    pose.position.y = path[i][5];
    pose.position.z = path[i][6];
    geometry_msgs::PoseStamped ps;
    ps.pose = pose;
    navPath.poses.push_back(ps);
  }
  nav_msgs::Path adaptedPath = adaptPath(dt, navPath, measuredWrench);

  for (int i = 0; i < path.size(); i++) {
    geometry_msgs::Pose pose;
    path[i][0] = adaptedPath.poses[i].pose.orientation.x;
    path[i][1] = adaptedPath.poses[i].pose.orientation.y;
    path[i][2] = adaptedPath.poses[i].pose.orientation.z;
    path[i][3] = adaptedPath.poses[i].pose.orientation.w;
    path[i][4] = adaptedPath.poses[i].pose.position.x;
    path[i][5] = adaptedPath.poses[i].pose.position.y;
    path[i][6] = adaptedPath.poses[i].pose.position.z;
  }
}

void AdmittanceReferenceModule::antiWindup() {
  wrenchIntegral_.getTorque().toImplementation() =
      wrenchIntegral_.getTorque().toImplementation().cwiseMax(-wrenchIntegralMax_.getTorque().toImplementation());
  wrenchIntegral_.getTorque().toImplementation() =
      wrenchIntegral_.getTorque().toImplementation().cwiseMin(wrenchIntegralMax_.getTorque().toImplementation());
  wrenchIntegral_.getForce().toImplementation() =
      wrenchIntegral_.getForce().toImplementation().cwiseMax(-wrenchIntegralMax_.getForce().toImplementation());
  wrenchIntegral_.getForce().toImplementation() =
      wrenchIntegral_.getForce().toImplementation().cwiseMin(wrenchIntegralMax_.getForce().toImplementation());
}

void AdmittanceReferenceModule::setDesiredEndeffectorWrench(const geometry_msgs::Wrench::ConstPtr& wrench) {
  std::lock_guard<std::mutex> lockGuard(desiredEEWrenchMutex_);
  kindr_ros::convertFromRosGeometryMsg(wrench->force, desiredEEWrench_.getForce());
  kindr_ros::convertFromRosGeometryMsg(wrench->torque, desiredEEWrench_.getTorque());
}