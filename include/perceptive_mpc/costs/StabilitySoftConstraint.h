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
#include <utility>

#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>
#include "perceptive_mpc/Definitions.h"

// CPPAD stuff
#include "cppad/cg/math.hpp"

namespace perceptive_mpc {

class StabilitySoftConstraint : public ocs2::RelaxedBarrierCost<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 1, 0> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef ocs2::RelaxedBarrierCost<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 1, 0> BASE;
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

  struct Settings {
    BASE::Config relaxedBarrierConfig = {1e-3, 1e-4};
    double supportCircleRadius = 0.3;
    std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics;
  };

  /**
   * Constructor
   */
  StabilitySoftConstraint(const Settings& settings) : BASE(settings.relaxedBarrierConfig), settings_(settings) {}

  /*
   * Copy constructor
   * @param rhs
   */
  StabilitySoftConstraint(const StabilitySoftConstraint& rhs) = default;

  /**
   * Default destructor
   */
  ~StabilitySoftConstraint() override = default;

  StabilitySoftConstraint* clone() const override;

  template <typename SCALAR_T>
  inline SCALAR_T computeCOMConstraintValue(const Eigen::Matrix<SCALAR_T, -1, 1>& state) const {
    using vector3_ad_t = Eigen::Matrix<SCALAR_T, 3, 1>;
    vector3_ad_t com = settings_.kinematics->getCOMBaseFrame(state);
    return settings_.supportCircleRadius * settings_.supportCircleRadius - com[0] * com[0] - com[1] * com[1];
  };

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
   * Gets a user-defined cost parameters, applied to the intermediate costs
   *
   * @param [in] time: Current time.
   * @return The cost function parameters at a certain time
   */
  virtual dynamic_vector_t getIntermediateParameters(scalar_t time) const override;

  /**
   * Number of parameters for the intermediate cost function.
   * This number must be remain constant after the model libraries are created
   *
   * @return number of parameters
   */
  virtual size_t getNumIntermediateParameters() const override;

 public:
  /**
   * Interpolate the reference trajectory
   *
   * @return The cost function parameters at a certain time
   */
  dynamic_vector_t interpolateReference(StabilitySoftConstraint::scalar_t time) const;

 private:
  const Settings settings_;
};

}  // namespace perceptive_mpc