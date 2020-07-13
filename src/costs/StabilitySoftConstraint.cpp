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
#include <perceptive_mpc/costs/InterpolatePoseTrajectory.h>
#include <perceptive_mpc/costs/StabilitySoftConstraint.h>

using namespace perceptive_mpc;

StabilitySoftConstraint* StabilitySoftConstraint::clone() const {
  return new StabilitySoftConstraint(*this);
}

void StabilitySoftConstraint::intermediateCostFunction(ad_scalar_t time, const ad_dynamic_vector_t& state, const ad_dynamic_vector_t& input,
                                                       const ad_dynamic_vector_t& parameters,
                                                       ad_intermediate_cost_vector_t& costValues) const {
  using vector3_ad_t = Eigen::Matrix<ad_scalar_t, 3, 1>;
  using vector6_ad_t = Eigen::Matrix<ad_scalar_t, 6, 1>;
  using vector7_ad_t = Eigen::Matrix<ad_scalar_t, 7, 1>;

  vector7_ad_t desiredPose = parameters.head<Definitions::POSE_DIM>();
  vector6_ad_t desiredWrench = parameters.tail<Definitions::WRENCH_DIM>();
  vector3_ad_t zmp = settings_.kinematics->getZMPBaseFrame(state, desiredPose, desiredWrench);

  costValues[0] = settings_.supportCircleRadius * settings_.supportCircleRadius - zmp[0] * zmp[0] - zmp[1] * zmp[1];
}

StabilitySoftConstraint::dynamic_vector_t StabilitySoftConstraint::getIntermediateParameters(StabilitySoftConstraint::scalar_t time) const {
  return interpolateReference(time);
}
size_t StabilitySoftConstraint::getNumIntermediateParameters() const {
  return Definitions::REFERENCE_DIM;
}

StabilitySoftConstraint::dynamic_vector_t StabilitySoftConstraint::interpolateReference(StabilitySoftConstraint::scalar_t time) const {
  StabilitySoftConstraint::dynamic_vector_t reference = StabilitySoftConstraint::dynamic_vector_t::Zero((int)Definitions::REFERENCE_DIM);
  const auto& desiredTimeTrajectory = costDesiredTrajectoriesPtr_->desiredTimeTrajectory();
  const auto& desiredStateTrajectory = costDesiredTrajectoriesPtr_->desiredStateTrajectory();
  reference.head((int)Definitions::POSE_DIM) = interpolatePoseTrajectory(desiredTimeTrajectory, desiredStateTrajectory, time);
  reference.tail((int)Definitions::WRENCH_DIM) = interpolateWrenchTrajectory(desiredTimeTrajectory, desiredStateTrajectory, time);
  return reference;
}
