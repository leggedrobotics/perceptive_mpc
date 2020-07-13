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

#include <perceptive_mpc/EsdfCachingServer.hpp>

namespace voxblox {

void EsdfCachingServer::esdfMapCallback(const voxblox_msgs::Layer& layer_msg) {
  EsdfServer::esdfMapCallback(layer_msg);
  auto start = std::chrono::high_resolution_clock::now();
  esdf_caching_layer_ptr incomingEsdfCached =
      esdf_caching_layer_ptr(new voxblox::Layer<voxblox::EsdfCachingVoxel>(getEsdfMapPtr()->getEsdfLayer()));
  auto stop = std::chrono::high_resolution_clock::now();
  using us = std::chrono::microseconds;
  us elapsedUs = std::chrono::duration_cast<us>(stop - start);
  std::cout << "create caching layer from incoming esdf: " << elapsedUs.count() << "us" << std::endl;

  start = std::chrono::high_resolution_clock::now();
  incomingEsdfCached->cacheGradients();
  stop = std::chrono::high_resolution_clock::now();
  elapsedUs = std::chrono::duration_cast<us>(stop - start);
  std::cout << "cache gradients: " << elapsedUs.count() << "us" << std::endl;

  //incomingEsdfCached->cacheHessians();
  {
    std::lock_guard<std::mutex> lockGuard(cacheMutex_);
    cachedCachingLayer_ = incomingEsdfCached;
  }
}
std::shared_ptr<voxblox::Interpolator<voxblox::EsdfCachingVoxel>> EsdfCachingServer::getInterpolator() {
  return interpolator_;
}
void EsdfCachingServer::updateInterpolator() {
  std::lock_guard<std::mutex> lockGuard(cacheMutex_);
  if (cachedCachingLayer_) {
    currentCachingLayer_ = cachedCachingLayer_;
    cachedCachingLayer_ = nullptr;
    *interpolator_ = voxblox::Interpolator<EsdfCachingVoxel>(currentCachingLayer_.get());
  }
}
EsdfCachingServer::EsdfCachingServer(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private) : EsdfServer(nh, nh_private) {
  currentCachingLayer_ = esdf_caching_layer_ptr(new voxblox::Layer<voxblox::EsdfCachingVoxel>(getEsdfMapPtr()->getEsdfLayer()));
  interpolator_.reset(new voxblox::Interpolator<EsdfCachingVoxel>(currentCachingLayer_.get()));
}

} /* namespace voxblox */