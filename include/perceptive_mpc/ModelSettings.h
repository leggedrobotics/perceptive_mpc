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

#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <string>

namespace perceptive_mpc {

class ModelSettings {
 public:
  ModelSettings() : recompileLibraries_(false) {}

  virtual ~ModelSettings() = default;

  /** flag to generate dynamic files **/
  bool recompileLibraries_;

  virtual void loadSettings(const std::string& filename, bool verbose = true);
};

inline void ModelSettings::loadSettings(const std::string& filename, bool verbose /*= true*/) {
  boost::property_tree::ptree pt;
  boost::property_tree::read_info(filename, pt);

  if (verbose) std::cerr << "\n #### Robot Model Settings:" << std::endl;
  if (verbose) std::cerr << " #### ==================================================" << std::endl;

  try {
    recompileLibraries_ = pt.get<bool>("model_settings.recompileLibraries");
    if (verbose) std::cerr << " #### recompileLibraries ..... " << recompileLibraries_ << std::endl;
  } catch (const std::exception& e) {
    if (verbose) std::cerr << " #### recompileLibraries ..... " << recompileLibraries_ << "\t(default)" << std::endl;
  }

  if (verbose) std::cerr << " #### ================================================ ####" << std::endl;
}

}  // namespace perceptive_mpc
