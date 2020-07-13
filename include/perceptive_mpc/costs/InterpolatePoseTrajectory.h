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
#include <ocs2_core/Dimensions.h>
#include <perceptive_mpc/Definitions.h>

namespace perceptive_mpc {

inline ocs2::dynamic_vector_t interpolatePoseTrajectory(const ocs2::scalar_array_t& timeTrajectory,
                                                        const ocs2::dynamic_vector_array_t& stateTrajectory, ocs2::scalar_t time) {
  ocs2::dynamic_vector_t reference((int)Definitions::POSE_DIM);

  auto it = std::lower_bound(timeTrajectory.begin(), timeTrajectory.end(), time);
  int timeAIdx = it - timeTrajectory.begin() - 1;
  if (timeAIdx == -1) {
    reference = stateTrajectory[0].head((int)Definitions::POSE_DIM);
    /*
        std::cerr << "t:" << t << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" << desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl << std::endl;
    */
  } else if (timeAIdx == timeTrajectory.size() - 1) {
    reference = stateTrajectory[timeAIdx].head((int)Definitions::POSE_DIM);
    ;
    /*
        std::cerr << "t:" << t << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" << desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl << std::endl;
    */
  } else {
    double tau = (time - timeTrajectory[timeAIdx]) / (timeTrajectory[timeAIdx + 1] - timeTrajectory[timeAIdx]);
    const Eigen::Quaterniond quatA(stateTrajectory[timeAIdx].head((int)Definitions::POSE_DIM).head<4>());
    const Eigen::Quaterniond quatB(stateTrajectory[timeAIdx + 1].head((int)Definitions::POSE_DIM).head<4>());
    // interpolate the quaternions using slerp
    reference.head<4>() = quatA.slerp(tau, quatB).coeffs();
    // interpolate cartesian space position linearly
    reference.tail<3>() = (1 - tau) * stateTrajectory[timeAIdx].head((int)Definitions::POSE_DIM).tail<3>() +
                          tau * stateTrajectory[timeAIdx + 1].head((int)Definitions::POSE_DIM).tail<3>();
    /*    std::cerr << "t:" << t << ", tau:" << tau << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" <<
       desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl
                  << "x_a: " << desiredStateTrajectory[timeAIdx].transpose() << std::endl
                  << "x_t: " << xNominal.transpose() << std::endl
                  << "x_b: " << desiredStateTrajectory[timeAIdx+1].transpose() << std::endl<< std::endl;*/
  }
  return reference;
}

inline ocs2::dynamic_vector_t interpolateWrenchTrajectory(const ocs2::scalar_array_t& timeTrajectory,
                                                          const ocs2::dynamic_vector_array_t& stateTrajectory, ocs2::scalar_t time) {
  ocs2::dynamic_vector_t reference((int)Definitions::WRENCH_DIM);

  auto it = std::lower_bound(timeTrajectory.begin(), timeTrajectory.end(), time);
  int timeAIdx = it - timeTrajectory.begin() - 1;
  if (timeAIdx == -1) {
    reference = stateTrajectory[0].tail((int)Definitions::WRENCH_DIM);
    /*
        std::cerr << "t:" << t << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" << desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl << std::endl;
    */
  } else if (timeAIdx == timeTrajectory.size() - 1) {
    reference = stateTrajectory[timeAIdx].tail((int)Definitions::WRENCH_DIM);
    ;
    /*
        std::cerr << "t:" << t << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" << desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl << std::endl;
    */
  } else {
    double tau = (time - timeTrajectory[timeAIdx]) / (timeTrajectory[timeAIdx + 1] - timeTrajectory[timeAIdx]);

    // interpolate cartesian space position linearly
    reference = (1 - tau) * stateTrajectory[timeAIdx].tail((int)Definitions::WRENCH_DIM) +
                tau * stateTrajectory[timeAIdx + 1].tail((int)Definitions::WRENCH_DIM);
    /*    std::cerr << "t:" << t << ", tau:" << tau << ", t_start:" << desiredTimeTrajectory.front() << ", t_stop:" <<
       desiredTimeTrajectory.back()
                  << std::endl << ", timeAIdx:" << timeAIdx << ", N:" << desiredTimeTrajectory.size() << ", t_idx:" <<
       desiredTimeTrajectory[timeAIdx] << std::endl
                  << "x_a: " << desiredStateTrajectory[timeAIdx].transpose() << std::endl
                  << "x_t: " << xNominal.transpose() << std::endl
                  << "x_b: " << desiredStateTrajectory[timeAIdx+1].transpose() << std::endl<< std::endl;*/
  }
  return reference;
}

}  // namespace perceptive_mpc
