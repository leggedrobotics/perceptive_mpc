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
#include <perceptive_mpc/Conversions.h>

using namespace perceptive_mpc;

void Conversions::writeMpcState(Conversions::state_vector_t& stateVector,
                                                const kindr::HomTransformQuatD& pose, const Eigen::VectorXd& armPositions) {
  stateVector.head<Definitions::BASE_STATE_DIM_>().head<4>() = pose.getRotation().toImplementation().coeffs();
  stateVector.head<Definitions::BASE_STATE_DIM_>().tail<3>() = pose.getPosition().toImplementation();
  stateVector.tail<Definitions::ARM_STATE_DIM_>() = armPositions;
}

void Conversions::readMpcState(const Conversions::state_vector_t& stateVector,
                                               kindr::HomTransformQuatD& pose, Eigen::VectorXd& armPositions) {
  pose.getRotation().toImplementation().coeffs() = stateVector.head<Definitions::BASE_STATE_DIM_>().head<4>();
  pose.getPosition().toImplementation() = stateVector.head<Definitions::BASE_STATE_DIM_>().tail<3>();
  armPositions = stateVector.tail<Definitions::ARM_STATE_DIM_>();
}

void Conversions::readMpcInput(const Conversions::input_vector_t& inputVector, kindr::TwistLocalD& twist, Eigen::VectorXd& armVelocities) {
  kindr::Velocity3D linearVelocity;
  linearVelocity(0) = inputVector[0];

  kindr::LocalAngularVelocityD angularVelocity;
  angularVelocity(2) = inputVector[1];

  twist.getTranslationalVelocity() = linearVelocity;
  twist.getRotationalVelocity() = angularVelocity;

  armVelocities = inputVector.tail<6>();
}