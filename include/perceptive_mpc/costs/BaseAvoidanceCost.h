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

#include <ocs2_core/cost/RelaxedBarrierCost.h>
#include <ocs2_robotic_tools/common/RotationTransforms.h>

#include <algorithm>
#include <cmath>
#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>
#include <utility>

#include "perceptive_mpc/Definitions.h"

// CPPAD stuff
#include "cppad/cg/math.hpp"

namespace perceptive_mpc {

struct BaseAvoidanceCostConfig {
  double widthX = 0.8;
  double widthY = 0.7;
  double reach = 1.1;

  double sigma = 10;
  double mu = 1e-3;
  double delta = 1e-4;

  std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics;
};

class BaseAvoidanceCost : public ocs2::RelaxedBarrierCost<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 2, 0> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef ocs2::RelaxedBarrierCost<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 2, 0> BASE;
  using typename BASE::ad_scalar_t;
  using typename BASE::dynamic_vector_t;
  using typename BASE::input_matrix_t;
  using typename BASE::input_vector_t;
  using typename BASE::scalar_t;
  using typename BASE::state_matrix_t;
  using typename BASE::state_vector_t;
  using state_cost_matrix_t = Eigen::Matrix<scalar_t, 6, 6>;
  using typename BASE::intermediate_cost_vector_t;
  using typename BASE::terminal_cost_vector_t;

  /**
   * Constructor
   */
  BaseAvoidanceCost(BaseAvoidanceCostConfig config = BaseAvoidanceCostConfig());

  /*
   * Copy constructor
   * @param rhs
   */
  BaseAvoidanceCost(const BaseAvoidanceCost& rhs) = default;

  /**
   * Default destructor
   */
  ~BaseAvoidanceCost() override = default;

  BaseAvoidanceCost* clone() const override;

  // overwrite getDerivative methods and return 0 when we know, that they should always return zero
  void getIntermediateCostDerivativeTime(scalar_t& dLdt) override final;
  void getIntermediateCostDerivativeInput(input_vector_t& dLdu) override final;
  void getIntermediateCostSecondDerivativeInput(input_matrix_t& dLduu) override;
  void getIntermediateCostDerivativeInputState(input_state_matrix_t& dLdux) override;
  void getTerminalCost(scalar_t& Phi) override final;
  void getTerminalCostDerivativeTime(scalar_t& dPhidt) override final;
  void getTerminalCostDerivativeState(state_vector_t& dPhidx) override final;
  void getTerminalCostSecondDerivativeState(state_matrix_t& dPhidxx) override;

 protected:
  /**
   * Interface method to the intermediate cost function.
   *
   * @tparam scalar type. All the floating point operations should be with this type.
   * @param [in] time: time.
   * @param [in] state: state vector.
   * @param [in] input: input vector.
   * @param [in] stateDesired: desired state vector.
   * @param [in] inputDesired: desired input vector.
   * @param [in] logicVariable: logic variable vector.
   * @param [out] costValue: cost value.
   */
  virtual void intermediateCostFunction(ad_scalar_t time, const ad_dynamic_vector_t& state, const ad_dynamic_vector_t& input,
                                        const ad_dynamic_vector_t& parameters, ad_intermediate_cost_vector_t& costValues) const override;

  /**
   * Number of parameters for the intermediate cost function.
   * This number must be remain constant after the model libraries are created
   *
   * @return number of parameters
   */
  virtual size_t getNumIntermediateParameters() const override;

  /**
   * Number of parameters for the terminal cost function.
   * This number must be remain constant after the model libraries are created
   *
   * @return number of parameters
   */
  virtual size_t getNumTerminalParameters() const override;

 private:
  double widthX_ = 0.8;
  double widthY_ = 0.7;
  double reach_ = 1.1;

  double sigma_ = 10;

  std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics_;

  ad_scalar_t obstacle1D(const ad_scalar_t& x, const double& width) const;
  ad_scalar_t obstacle2D(const ad_scalar_t& x, const ad_scalar_t& y) const;
};

}  // namespace perceptive_mpc