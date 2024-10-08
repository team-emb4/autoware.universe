// Copyright 2021 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AUTOWARE__SIGNAL_PROCESSING__LOWPASS_FILTER_1D_HPP_
#define AUTOWARE__SIGNAL_PROCESSING__LOWPASS_FILTER_1D_HPP_

#include <boost/optional.hpp>

namespace autoware::signal_processing
{
double lowpassFilter(const double current_val, const double prev_val, const double gain);

/**
 * @class First-order low-pass filter
 * @brief filtering values
 */
class LowpassFilter1d
{
private:
  boost::optional<double> x_;  //!< @brief current filtered value
  double gain_;                //!< @brief gain value of first-order low-pass filter

public:
  explicit LowpassFilter1d(const double gain);

  void reset();
  void reset(const double x);

  void setGain(const double gain);

  boost::optional<double> getValue() const;
  double filter(const double u);
};
}  // namespace autoware::signal_processing

#endif  // AUTOWARE__SIGNAL_PROCESSING__LOWPASS_FILTER_1D_HPP_
