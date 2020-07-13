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

#include <perceptive_mpc/ExplicitTemplateInstantiations.h>
#include <kindr/Core>
#include <Eigen/Core>

namespace perceptive_mpc {

class Conversions {
 public:
  typedef ocs2::SystemObservation<perceptive_mpc::STATE_DIM_, perceptive_mpc::INPUT_DIM_> Observation;
  typedef Observation::state_vector_t state_vector_t;
  typedef Observation::input_vector_t input_vector_t;

  static void writeMpcState(state_vector_t& stateVector, const kindr::HomTransformQuatD& pose, const Eigen::VectorXd& armPositions);
  static void readMpcState(const state_vector_t& stateVector, kindr::HomTransformQuatD& pose, Eigen::VectorXd& armPositions);

  static void readMpcInput(const input_vector_t& inputVector, kindr::TwistLocalD& twist, Eigen::VectorXd& armVelocities);

};

}  // namespace smb_path_following