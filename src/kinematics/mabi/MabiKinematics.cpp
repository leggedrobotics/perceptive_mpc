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

#include <iit/rbd/rbd.h>
#include <iit/rbd/traits/TraitSelector.h>
#include "generated/inertia_properties.h"
#include "generated/transforms.h"

#include <perceptive_mpc/kinematics/mabi/MabiKinematics.hpp>

using namespace perceptive_mpc;

template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 4, 4> MabiKinematics<SCALAR_T>::computeArmMountToToolMountTransform(
    const Eigen::Matrix<SCALAR_T, 6, 1>& armState) const {
  typedef typename iit::rbd::tpl::TraitSelector<SCALAR_T>::Trait trait_t;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_arm_mount_X_fr_WRIST_2 armMountToWrist2Transform;
  const Eigen::Matrix<SCALAR_T, 4, 4> homBase2Wrist2Transform = armMountToWrist2Transform.update(armState);
  return homBase2Wrist2Transform;
}

template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 3, -1> MabiKinematics<SCALAR_T>::computeArmState2MultiplePointsOnRobot(
    const Eigen::Matrix<SCALAR_T, 6, 1>& state, const std::vector<std::vector<double>>& points,
    const Eigen::Matrix4d& transformBase_X_ArmBase, const Eigen::Matrix4d& transformToolMount_X_Endeffector,
    const Eigen::Matrix<SCALAR_T, 4, 4>& transformWorld_X_Base) const {
  assert(points.size() == 8);

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

  Eigen::Matrix<SCALAR_T, 4, 4> transformWorld_X_Endeffector = transformWorld_X_Base;

  typedef typename iit::rbd::tpl::TraitSelector<SCALAR_T>::Trait trait_t;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_arm_mount_X_fr_SHOULDER armMountXFrShoulderXFrShoulder;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_SHOULDER_X_fr_ARM shoulderXFrArm;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_ARM_X_fr_ELBOW armXFrElbow;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_ELBOW_X_fr_FOREARM elbowXFrForearm;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_FOREARM_X_fr_WRIST_1 forearmXFrWrist1;
  typename iit::mabi::tpl::HomogeneousTransforms<trait_t>::Type_fr_WRIST_1_X_fr_WRIST_2 wrist1XFrWrist2;

  Eigen::Matrix<SCALAR_T, 4, 4> nextStep = transformBase_X_ArmBase.cast<SCALAR_T>();
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = armMountXFrShoulderXFrShoulder.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = shoulderXFrArm.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = armXFrElbow.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = elbowXFrForearm.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = forearmXFrWrist1.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = wrist1XFrWrist2.update(state);
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  nextStep = transformToolMount_X_Endeffector.cast<SCALAR_T>();
  for (int i = 0; i < points[linkIndex].size(); i++) {
    Eigen::Matrix<SCALAR_T, 4, 1> directionVector = nextStep.col(3);
    directionVector.template head<3>() = directionVector.template head<3>() * (SCALAR_T)points[linkIndex][i];
    result.col(resultIndex++) = (transformWorld_X_Endeffector * directionVector).template head<3>();
  }
  linkIndex++;
  transformWorld_X_Endeffector = transformWorld_X_Endeffector * nextStep;

  return result;
}
template <typename SCALAR_T>
double MabiKinematics<SCALAR_T>::getArmMass() const {
  iit::mabi::dyn::InertiaProperties inertiaProperties;
  return inertiaProperties.getTotalMass();
}
template <typename SCALAR_T>
Eigen::Matrix<SCALAR_T, 3, 1> MabiKinematics<SCALAR_T>::getArmCOM(const Eigen::Matrix<SCALAR_T, 6, 1>& armState) const {
  using trait_t = typename iit::rbd::tpl::TraitSelector<SCALAR_T>::Trait;
  iit::mabi::dyn::tpl::InertiaProperties<trait_t> inertiaProps;
  iit::mabi::dyn::InertiaProperties inertiaPropsDouble;
  using hom_transforms_t = typename iit::mabi::tpl::HomogeneousTransforms<trait_t>;
  using vector3_t = Eigen::Matrix<SCALAR_T, 3, 1>;
  hom_transforms_t ht;

  vector3_t tmpSum(vector3_t::Zero());

  typename hom_transforms_t::MatrixType tmpX(hom_transforms_t::MatrixType::Identity());
  tmpX =
      tmpX * ht.fr_arm_mount_X_fr_SHOULDER.update(
                 armState);  // the original generated code took the transformation from world to shoulder. We use the arm mount frame here
  tmpSum += inertiaProps.getMass_SHOULDER() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_SHOULDER()));

  tmpX = tmpX * ht.fr_SHOULDER_X_fr_ARM.update(armState);
  tmpSum += inertiaProps.getMass_ARM() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_ARM()));

  tmpX = tmpX * ht.fr_ARM_X_fr_ELBOW.update(armState);
  tmpSum += inertiaProps.getMass_ELBOW() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_ELBOW()));

  tmpX = tmpX * ht.fr_ELBOW_X_fr_FOREARM.update(armState);
  tmpSum += inertiaProps.getMass_FOREARM() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_FOREARM()));

  tmpX = tmpX * ht.fr_FOREARM_X_fr_WRIST_1.update(armState);
  tmpSum += inertiaProps.getMass_WRIST_1() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_WRIST_1()));

  tmpX = tmpX * ht.fr_WRIST_1_X_fr_WRIST_2.update(armState);
  tmpSum += inertiaProps.getMass_WRIST_2() * (iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_WRIST_2()));

  return tmpSum / (SCALAR_T)inertiaPropsDouble.getTotalMass();
}
template <typename SCALAR_T>
MabiKinematics<SCALAR_T>::MabiKinematics(const KinematicInterfaceConfig& config) : Base(config) {}

template class perceptive_mpc::MabiKinematics<double>;
template class perceptive_mpc::MabiKinematics<CppAD::AD<CppAD::cg::CG<double>>>;