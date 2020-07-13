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
#include <Eigen/Dense>
#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>

using namespace perceptive_mpc;

template <typename SCALAR_T>
KinematicsInterface<SCALAR_T>::KinematicsInterface(const KinematicInterfaceConfig& config) : config_(config) {}

template <typename SCALAR_T>
void KinematicsInterface<SCALAR_T>::computeState2EndeffectorTransform(Eigen::Matrix<SCALAR_T, 4, 4>& transform,
                                                                      const Eigen::Matrix<SCALAR_T, -1, 1>& state) const {
  if (state.size() != 13) {
    std::stringstream ss;
    ss << "Error: state.size()=" << state.size() << "!=13";
    std::string errorMessage = ss.str();
    std::cerr << std::endl << errorMessage << std::endl << std::endl;
    throw std::runtime_error(ss.str());
  }

  Eigen::Quaternion<SCALAR_T> baseOrientation;
  baseOrientation.coeffs() = state.template head<7>().template head<4>();
  const Eigen::Matrix<SCALAR_T, 3, 1>& basePosition = state.template head<7>().template tail<3>();
  const Eigen::Matrix<SCALAR_T, 6, 1>& armState = state.template tail<6>();

  // homogeneous transform world -> base
  Eigen::Matrix<SCALAR_T, 4, 4> homWorld2Base = Eigen::Matrix<SCALAR_T, 4, 4>::Identity();
  homWorld2Base.template topLeftCorner<3, 3>() = baseOrientation.toRotationMatrix();
  homWorld2Base.template topRightCorner<3, 1>() = basePosition;

  // world -> endeffector
  transform = homWorld2Base * computeBase2EndeffectorTransform(armState);
}

template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 4, 4> KinematicsInterface<SCALAR_T>::computeBase2EndeffectorTransform(
    const Eigen::Matrix<SCALAR_T, 6, 1>& armState) const {
  const Eigen::Matrix<SCALAR_T, 4, 4> armBaseToWrist2Transform = computeArmMountToToolMountTransform(armState);
  return config_.transformBase_X_ArmMount.template cast<SCALAR_T>() * armBaseToWrist2Transform *
         config_.transformToolMount_X_Endeffector.template cast<SCALAR_T>();
}

template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 3, -1> KinematicsInterface<SCALAR_T>::computeState2MultiplePointsOnRobot(
    const Eigen::Matrix<SCALAR_T, -1, 1>& state, const std::vector<std::vector<double>>& points) const {
  if (state.size() != 13) {
    std::stringstream ss;
    ss << "Error: state.size()=" << state.size() << "!=13";
    std::string errorMessage = ss.str();
    std::cerr << std::endl << errorMessage << std::endl << std::endl;
    throw std::runtime_error(ss.str());
  }

  int dim = 0;
  for (int i = 0; i < points.size(); i++) {
    for (int j = 0; j < points[i].size(); j++) {
      dim++;
    }
  }
  if (dim == 0) {
    return Eigen::Matrix<SCALAR_T, 3, -1>(3, 0);
  }
  Eigen::Matrix<SCALAR_T, 3, -1> result(3, dim);
  int resultIndex = 0;
  int linkIndex;

  Eigen::Quaternion<SCALAR_T> baseOrientation;
  baseOrientation.coeffs() = state.template head<7>().template head<4>();
  const Eigen::Matrix<SCALAR_T, 3, 1>& basePosition = state.template head<7>().template tail<3>();
  const Eigen::Matrix<SCALAR_T, 6, 1>& armState = state.template tail<6>();

  Eigen::Matrix<SCALAR_T, 4, 4> worldXFrBase = Eigen::Matrix<SCALAR_T, 4, 4>::Identity();
  worldXFrBase.template topLeftCorner<3, 3>() = baseOrientation.toRotationMatrix();
  worldXFrBase.template topRightCorner<3, 1>() = basePosition;

  return computeArmState2MultiplePointsOnRobot(armState, points, config_.transformBase_X_ArmMount, config_.transformToolMount_X_Endeffector,
                                               worldXFrBase);
}

template <typename SCALAR_T>
Eigen::Quaternion<SCALAR_T> KinematicsInterface<SCALAR_T>::matrixToQuaternion(const Eigen::Matrix<SCALAR_T, 3, 3>& R) const {
  SCALAR_T t1, t2, t;
  SCALAR_T x1, x2, x;
  SCALAR_T y1, y2, y;
  SCALAR_T z1, z2, z;
  SCALAR_T w1, w2, w;

  t1 = CppAD::CondExpGt(R(0, 0), R(1, 1), 1 + R(0, 0) - R(1, 1) - R(2, 2), 1 - R(0, 0) + R(1, 1) - R(2, 2));
  t2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), 1 - R(0, 0) - R(1, 1) + R(2, 2), 1 + R(0, 0) + R(1, 1) + R(2, 2));
  t = CppAD::CondExpLt(R(2, 2), SCALAR_T(0.0), t1, t2);

  x1 = CppAD::CondExpGt(R(0, 0), R(1, 1), t, R(1, 0) + R(0, 1));
  x2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(0, 2) + R(2, 0), R(2, 1) - R(1, 2));
  x = CppAD::CondExpLt(R(2, 2), SCALAR_T(0.0), x1, x2);

  y1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(1, 0) + R(0, 1), t);
  y2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(2, 1) + R(1, 2), R(0, 2) - R(2, 0));
  y = CppAD::CondExpLt(R(2, 2), SCALAR_T(0.0), y1, y2);

  z1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(0, 2) + R(2, 0), R(2, 1) + R(1, 2));
  z2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), t, R(1, 0) - R(0, 1));
  z = CppAD::CondExpLt(R(2, 2), SCALAR_T(0.0), z1, z2);

  w1 = CppAD::CondExpGt(R(0, 0), R(1, 1), R(2, 1) - R(1, 2), R(0, 2) - R(2, 0));
  w2 = CppAD::CondExpLt(R(0, 0), -R(1, 1), R(1, 0) - R(0, 1), t);
  w = CppAD::CondExpLt(R(2, 2), SCALAR_T(0.0), w1, w2);

  Eigen::Matrix<SCALAR_T, 4, 1> q({x, y, z, w});
  q *= 0.5 / sqrt(t);

  Eigen::Quaternion<SCALAR_T> quaternion;
  quaternion.x() = q(0);
  quaternion.y() = q(1);
  quaternion.z() = q(2);
  quaternion.w() = q(3);

  return quaternion;
}
template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 3, 1> KinematicsInterface<SCALAR_T>::getCOMBaseFrame(const Eigen::Matrix<SCALAR_T, -1, 1>& state) const {
  const Eigen::Matrix<SCALAR_T, 6, 1>& armState = state.template tail<6>();
  Eigen::Matrix<SCALAR_T, 4, 1> armCOM = Eigen::Matrix<SCALAR_T, 4, 1>::Ones();
  armCOM.template head<3>() = getArmCOM(armState);
  Eigen::Matrix<SCALAR_T, 3, 1> armCOMBaseFrame = (config_.transformBase_X_ArmMount.template cast<SCALAR_T>() * armCOM).template head<3>();
  double armMass = getArmMass();
  return ((SCALAR_T)armMass * armCOMBaseFrame + (config_.baseMass * config_.baseCOM).template cast<SCALAR_T>()) /
         (SCALAR_T)(armMass + config_.baseMass);
}
template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 3, 1> KinematicsInterface<SCALAR_T>::getZMPBaseFrame(
    const Eigen::Matrix<SCALAR_T, -1, 1>& state, const Eigen::Matrix<SCALAR_T, 7, 1>& eePoseReference,
    const Eigen::Matrix<SCALAR_T, 6, 1>& wrenchReferenceEEFrame) const {
  using vector3_t = Eigen::Matrix<SCALAR_T, 3, 1>;
  using hom_transform_t = Eigen::Matrix<SCALAR_T, 4, 4>;
  vector3_t rcog = getCOMBaseFrame(state);
  double robotMass = config_.baseMass + getArmMass();

  // convert reference force from fixed ee frame to base frame
  hom_transform_t worldToEndeffectorReference = hom_transform_t::Zero();
  worldToEndeffectorReference.template block<3, 3>(0, 0) =
      Eigen::Quaternion<SCALAR_T>(eePoseReference.template head<4>()).toRotationMatrix();
  worldToEndeffectorReference.template block<3, 1>(0, 3) = eePoseReference.template tail<3>();
  worldToEndeffectorReference(3, 3) = 1;

  hom_transform_t worldToBase = getWorldToBaseTransform(state);
  hom_transform_t baseToWorld = worldToBase;
  baseToWorld.template block<3, 3>(0, 0) = worldToBase.template block<3, 3>(0, 0).transpose();
  baseToWorld.template block<3, 1>(0, 3) = -baseToWorld.template block<3, 3>(0, 0) * worldToBase.template block<3, 1>(0, 3);

  hom_transform_t baseToEndeffectorReference = baseToWorld * worldToEndeffectorReference;
  vector3_t forceBaseFrame = baseToEndeffectorReference.template block<3, 3>(0, 0) * wrenchReferenceEEFrame.template head<3>();
  vector3_t torqueBaseFrame = baseToEndeffectorReference.template block<3, 3>(0, 0) * wrenchReferenceEEFrame.template tail<3>();

  // compute a virtual mass for the acting end-effector force
  const double g = 9.81;
  vector3_t fg;
  fg << (SCALAR_T)0, (SCALAR_T)0, (SCALAR_T)-robotMass * g;

  // compute translation to the virtual mass in base frame
  hom_transform_t base_X_Endeffector = computeBase2EndeffectorTransform(state.template tail<6>());
  vector3_t ree = base_X_Endeffector.template block<3, 1>(0, 3);

  vector3_t n;
  n << (SCALAR_T)0, (SCALAR_T)0, (SCALAR_T)1;

  return n.template cross(rcog.cross(fg) + ree.cross(forceBaseFrame) + torqueBaseFrame) / n.dot(fg + forceBaseFrame);
}

template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 4, 4> KinematicsInterface<SCALAR_T>::getWorldToBaseTransform(const Eigen::Matrix<SCALAR_T, -1, 1>& state) const {
  Eigen::Quaternion<SCALAR_T> baseOrientation;
  baseOrientation.coeffs() = state.template head<7>().template head<4>();
  const Eigen::Matrix<SCALAR_T, 3, 1>& basePosition = state.template head<7>().template tail<3>();

  // homogeneous transform world -> base
  Eigen::Matrix<SCALAR_T, 4, 4> homWorld2Base = Eigen::Matrix<SCALAR_T, 4, 4>::Identity();
  homWorld2Base.template topLeftCorner<3, 3>() = baseOrientation.toRotationMatrix();
  homWorld2Base.template topRightCorner<3, 1>() = basePosition;
  return homWorld2Base;
}

template class perceptive_mpc::KinematicsInterface<double>;
template class perceptive_mpc::KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>;