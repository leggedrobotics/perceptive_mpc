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
#include "perceptive_mpc/Definitions.h"

namespace perceptive_mpc {

class OperatingPoint : public ocs2::SystemOperatingPoint<perceptive_mpc::STATE_DIM_, perceptive_mpc::INPUT_DIM_> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef std::shared_ptr<OperatingPoint> Ptr;
  typedef std::shared_ptr<const OperatingPoint> ConstPtr;

  typedef ocs2::SystemOperatingPoint<perceptive_mpc::STATE_DIM_, perceptive_mpc::INPUT_DIM_> BASE;
  typedef typename Base::scalar_t scalar_t;
  typedef typename Base::scalar_array_t scalar_array_t;
  typedef typename Base::size_array_t size_array_t;
  typedef typename Base::state_vector_t state_vector_t;
  typedef typename Base::state_vector_array_t state_vector_array_t;
  typedef typename Base::input_vector_t input_vector_t;
  typedef typename Base::input_vector_array_t input_vector_array_t;

  /**
   * Constructor
   *
   */
  OperatingPoint() = default;

  /**
   * Destructor
   */
  ~OperatingPoint() = default;

  /**
   * Returns pointer to the class.
   *
   * @return A raw pointer to the class.
   */
  OperatingPoint* clone() const final { return new OperatingPoint(*this); }

  /**
   * Gets the operating points for the system in time interval [startTime, finalTime] where there is
   * no intermediate switches except possibly the end time.
   *
   * @param [in] initialState: Initial state.
   * @param [in] startTime: Initial time.
   * @param [in] finalTime: Final time.
   * @param [out] timeTrajectory: Output time stamp trajectory.
   * @param [out] stateTrajectory: Output state trajectory.
   * @param [out] inputTrajectory: Output control input trajectory.
   * @param [in] concatOutput: Whether to concatenate the output to the input trajectories or
   * override (default).
   */
  void getSystemOperatingTrajectories(const state_vector_t& initialState, const scalar_t& startTime, const scalar_t& finalTime,
                                      scalar_array_t& timeTrajectory, state_vector_array_t& stateTrajectory,
                                      input_vector_array_t& inputTrajectory, bool concatOutput = false) final;

 private:
};

}  // namespace perceptive_mpc