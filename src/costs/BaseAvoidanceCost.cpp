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
#include <perceptive_mpc/costs/BaseAvoidanceCost.h>

using namespace perceptive_mpc;

BaseAvoidanceCost::BaseAvoidanceCost(BaseAvoidanceCostConfig config)
    : RelaxedBarrierCost(RelaxedBarrierCost::Config{.mu = config.mu, .delta = config.delta}),
      sigma_(config.sigma),
      widthX_(config.widthX),
      widthY_(config.widthY),
      reach_(config.reach),
      kinematics_(config.kinematics){}

BaseAvoidanceCost* BaseAvoidanceCost::clone() const {
  return new BaseAvoidanceCost(*this);
}

void BaseAvoidanceCost::intermediateCostFunction(ad_scalar_t time, const ad_dynamic_vector_t& state, const ad_dynamic_vector_t& input,
                                                 const ad_dynamic_vector_t& parameters, ad_intermediate_cost_vector_t& costValues) const {
  const Eigen::Matrix<ad_scalar_t, 6, 1>& armState = state.tail<perceptive_mpc::ARM_STATE_DIM_>();
  Eigen::Matrix<ad_scalar_t, 4, 4> eeTransform = kinematics_->computeBase2EndeffectorTransform(
      armState);
  const Eigen::Matrix<ad_scalar_t, 3, 1>& currentPosition = eeTransform.topRightCorner<3, 1>();
  const ad_scalar_t& x = currentPosition(0);
  const ad_scalar_t& y = currentPosition(1);

  costValues = ad_intermediate_cost_vector_t();

  // reach constraint:
  costValues(0) = sigma_ * (reach_ * reach_ - x * x - y * y);
  // base avoidance:
  costValues(1) = sigma_ * obstacle2D(x, y);
}

size_t BaseAvoidanceCost::getNumIntermediateParameters() const {
  return 0;
}

size_t BaseAvoidanceCost::getNumTerminalParameters() const {
  return 0;
}

BaseAvoidanceCost::ad_scalar_t BaseAvoidanceCost::obstacle1D(const ad_scalar_t& x, const double& width) const {
  ad_scalar_t a = x - width / 2;
  ad_scalar_t b = -x - width / 2;
  ad_scalar_t zero(0);
  return CppAD::CondExpGt(x, (ad_scalar_t)0, a, b);
}

BaseAvoidanceCost::ad_scalar_t BaseAvoidanceCost::obstacle2D(const ad_scalar_t& x, const ad_scalar_t& y) const {
  ad_scalar_t costX = obstacle1D(x, widthX_);
  ad_scalar_t costY = obstacle1D(y, widthY_);
  return CppAD::CondExpGt(costX, costY, costX, costY);
}
void BaseAvoidanceCost::getIntermediateCostDerivativeTime(scalar_t& dLdt) {
  dLdt = 0;
}
void BaseAvoidanceCost::getIntermediateCostDerivativeInput(input_vector_t& dLdu) {
  dLdu = input_vector_t::Zero();
}
void BaseAvoidanceCost::getIntermediateCostSecondDerivativeInput(input_matrix_t& dLduu) {
  dLduu = input_matrix_t::Zero();
}
void BaseAvoidanceCost::getIntermediateCostDerivativeInputState(input_state_matrix_t& dLdux) {
  dLdux = input_state_matrix_t::Zero();
}
void BaseAvoidanceCost::getTerminalCost(scalar_t& Phi) {
  Phi = 0;
}
void BaseAvoidanceCost::getTerminalCostDerivativeTime(scalar_t& dPhidt) {
  dPhidt = 0;
}
void BaseAvoidanceCost::getTerminalCostDerivativeState(state_vector_t& dPhidx) {
  dPhidx = state_vector_t::Zero();
}
void BaseAvoidanceCost::getTerminalCostSecondDerivativeState(state_matrix_t& dPhidxx) {
  dPhidxx = state_matrix_t::Zero();
}
