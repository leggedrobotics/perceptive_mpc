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

#include <ocs2_core/cost/QuadraticGaussNewtonCostBaseAD.h>
#include <ocs2_robotic_tools/common/RotationTransforms.h>

#include <algorithm>
#include <cmath>
#include <utility>

#include <perceptive_mpc/kinematics/KinematicsInterface.hpp>
#include "perceptive_mpc/Definitions.h"

// CPPAD stuff
#include "cppad/cg/math.hpp"

namespace perceptive_mpc {

struct QuadraticEndeffectorTrackingCostConfig {
  Eigen::Matrix<double, 6, 6> eePoseQ = Eigen::Matrix<double, 6, 6>::Identity();
  Eigen::Matrix<double, 6, 6> eePoseQFinal = Eigen::Matrix<double, 6, 6>::Zero();
  Eigen::Matrix<double, 8, 8> R = Eigen::Matrix<double, 8, 8>::Identity();
  Eigen::Matrix4d wrist2ToEETransform = Eigen::Matrix4d::Identity();
  Eigen::Matrix4d baseToArmMount = Eigen::Matrix4d::Identity();
  std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics;
};

class QuadraticEndeffectorTrackingCost
    : public ocs2::QuadraticGaussNewtonCostBaseAD<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 6 + Definitions::INPUT_DIM_, 6> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  typedef ocs2::QuadraticGaussNewtonCostBaseAD<Definitions::STATE_DIM_, Definitions::INPUT_DIM_, 6 + Definitions::INPUT_DIM_, 6> BASE;
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
  QuadraticEndeffectorTrackingCost(const QuadraticEndeffectorTrackingCostConfig& config)
      : eePoseQ_(config.eePoseQ), eePoseQFinal_(config.eePoseQFinal), R_(config.R), kinematics_(config.kinematics) {}

  /*
   * Copy constructor
   * @param rhs
   */
  QuadraticEndeffectorTrackingCost(const QuadraticEndeffectorTrackingCost& rhs) = default;

  /**
   * Default destructor
   */
  ~QuadraticEndeffectorTrackingCost() override = default;

  QuadraticEndeffectorTrackingCost* clone() const override;

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
   * Interface method to the terminal cost function. This method should be implemented by the derived class.
   *
   * @tparam scalar type. All the floating point operations should be with this type.
   * @param [in] time: time.
   * @param [in] state: state vector.
   * @param [in] stateDesired: desired state vector.
   * @param [in] logicVariable: logic variable vector.
   * @param [out] costValue: cost value.
   */
  virtual void terminalCostFunction(ad_scalar_t time, const ad_dynamic_vector_t& state, const ad_dynamic_vector_t& parameters,
                                    ad_terminal_cost_vector_t& costValues) const override;

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

  /**
   * Gets a user-defined cost parameters, applied to the terminal costs
   *
   * @return The cost function parameters at a certain time
   */
  virtual dynamic_vector_t getTerminalParameters(scalar_t time) const override;

  /**
   * Interpolate the reference trajectory
   *
   * @return The cost function parameters at a certain time
   */
  dynamic_vector_t interpolateReference(QuadraticEndeffectorTrackingCost::scalar_t time) const;

  /**
   * Number of parameters for the terminal cost function.
   * This number must be remain constant after the model libraries are created
   *
   * @return number of parameters
   */
  virtual size_t getNumTerminalParameters() const override;

  Eigen::Quaternion<ad_scalar_t> matrixToQuaternion(const Eigen::Matrix<ad_scalar_t, 3, 3>& R) const;

 private:
  const state_cost_matrix_t eePoseQ_;
  const input_matrix_t R_;
  const state_cost_matrix_t eePoseQFinal_;
  const std::shared_ptr<const KinematicsInterface<CppAD::AD<CppAD::cg::CG<double>>>> kinematics_;
};

}  // namespace perceptive_mpc