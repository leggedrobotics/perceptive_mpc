/*
 * Copyright (c) 2020 Johannes Pankert <pankertj@ethz.ch>, Giuseppe Rizzi
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

// perceptive_mpc
#include <example/PerceptiveMpcInterface.h>
#include <perceptive_mpc/ExplicitTemplateInstantiations.h>
#include <perceptive_mpc/costs/PointsOnRobot.h>

#include <perceptive_mpc/Definitions.h>
#include <perceptive_mpc/WrenchPoseTrajectory.h>

// ocs2
#include <ocs2_core/automatic_differentiation/CppAdInterface.h>

// ros
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <std_srvs/Empty.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>

#include <atomic>
#include <boost/thread.hpp>

#include <kindr/Core>

#include <perceptive_mpc/EsdfCachingServer.hpp>
// TODO: uncomment for admittance control on hardware:
// #include <perceptive_mpc/AdmittanceReferenceModule.hpp>

namespace perceptive_mpc {

class KinematicSimulation {
 public:
  typedef ocs2::SystemObservation<perceptive_mpc::STATE_DIM_, perceptive_mpc::INPUT_DIM_> Observation;
  typedef ocs2::MPC_MRT_Interface<perceptive_mpc::STATE_DIM_, perceptive_mpc::INPUT_DIM_> MpcInterface;
  typedef MpcInterface::input_vector_t InputVector;
  using reference_vector_t = Eigen::Matrix<double, Definitions::REFERENCE_DIM, 1>;

  explicit KinematicSimulation(const ros::NodeHandle& nh = ros::NodeHandle());

  bool run();

 protected:
  std::string mpcTaskFile_;
  std::unique_ptr<perceptive_mpc::PerceptiveMpcInterface> ocs2Interface_;
  std::shared_ptr<MpcInterface> mpcInterface_;
  std::shared_ptr<PointsOnRobot> pointsOnRobot_;
  std::shared_ptr<voxblox::EsdfCachingServer> esdfCachingServer_;
  // TODO: uncomment for admittance control on hardware:
  // AdmittanceReferenceModule admittanceReferenceModule;

  // params
  double mpcUpdateFrequency_;
  double tfUpdateFrequency_;
  double controlLoopFrequency_;
  double maxLinearVelocity_;
  double maxAngularVelocity_;
  Eigen::Vector3d defaultForce_ = Eigen::Vector3d::Zero();
  Eigen::Vector3d defaultTorque_ = Eigen::Vector3d::Zero();

  // flags
  std::atomic_bool planAvailable_;
  std::atomic_bool mpcUpdateFailed_;

  double initialTime_;
  MpcInterface::state_vector_t optimalState_;

  boost::shared_mutex observationMutex_;
  Observation observation_;

  KinematicInterfaceConfig kinematicInterfaceConfig_;

  boost::shared_mutex costDesiredTrajectoryMutex_;
  ocs2::CostDesiredTrajectories costDesiredTrajectories_;

  // ros
  ros::NodeHandle nh_;
  ros::Publisher armStatePublisher_;
  ros::Publisher endEffectorPosePublisher_;
  ros::Publisher pointsOnRobotPublisher_;
  ros::Publisher comPublisher_;
  ros::Publisher zmpPublisher_;
  ros::Subscriber desiredEndEffectorPoseSubscriber_;
  ros::Subscriber desiredEndEffectorWrenchPoseTrajectorySubscriber_;
  tf::TransformBroadcaster tfBroadcaster_;

 protected:
  // thread 1 simulates the control loop: query new mpc plan, writes observation
  bool trackerLoop(ros::Rate rate);

  // thread 2 is the mpc solver
  bool mpcUpdate(ros::Rate rate);

  // thread 3 updates the tf for visualization
  bool tfUpdate(ros::Rate rate);

  // compute the current end effector Pose on the base of the latest observation
  kindr::HomTransformQuatD getEndEffectorPose();

  // publish the transform from odom to the robot base
  void publishBaseTransform(const Observation& observation);

  // publish the joint state message of the arm state
  void publishArmState(const Observation& observation);

  // publish the current end effector pose to ros
  void publishEndEffectorPose();

  void publishZmp(const Observation & observation, const ocs2::CostDesiredTrajectories& costDesiredTrajectories);

    // parse all ros parameters
  void parseParameters();

  std::shared_ptr<VoxbloxCostConfig> configureCollisionAvoidance(std::shared_ptr<KinematicsInterfaceAD> kinematicInterface);

  // update the desired end effector pose on ros msg
  void desiredEndEffectorPoseCb(const geometry_msgs::PoseStampedConstPtr& msgPtr);

  void desiredWrenchPoseTrajectoryCb(const perceptive_mpc::WrenchPoseTrajectory& wrenchPoseTrajectory);

  // make sure the forwarded integrated state is normalized to unit quaternion observation for the base rotation
  void setCurrentObservation(const Observation& observation);

  void loadTransforms();
  void initializeCostDesiredTrajectory();
};
}  // namespace perceptive_mpc