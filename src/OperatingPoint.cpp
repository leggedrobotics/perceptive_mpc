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
#include <perceptive_mpc/OperatingPoint.h>

using namespace perceptive_mpc;

void OperatingPoint::getSystemOperatingTrajectories(const state_vector_t& initialState, const scalar_t& startTime,
                                                    const scalar_t& finalTime, scalar_array_t& timeTrajectory,
                                                    state_vector_array_t& stateTrajectory, input_vector_array_t& inputTrajectory,
                                                    bool concatOutput ) {
  if (concatOutput == false) {
    timeTrajectory.clear();
    stateTrajectory.clear();
    inputTrajectory.clear();
  }

  timeTrajectory.emplace_back(startTime);
  timeTrajectory.emplace_back(finalTime);

  stateTrajectory.emplace_back(initialState);
  stateTrajectory.emplace_back(initialState);

  inputTrajectory.emplace_back(input_vector_t::Zero());
  inputTrajectory.emplace_back(input_vector_t::Zero());
}