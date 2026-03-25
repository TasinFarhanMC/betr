#ifndef BETR_CHRONO_HPP
#define BETR_CHRONO_HPP

#include "ratio.hpp"
#include <chrono>

namespace betr {
using std::chrono::duration_cast;
using std::chrono::duration_values;
using std::chrono::time_point_cast;

template <typename clock, typename duration = typename clock::duration> using TimePoint = std::chrono::time_point<clock, duration>;
template <typename T, typename ratio = Unit> using Duration = std::chrono::duration<T, ratio>;

using NanoSeconds = Duration<i64, Nano>;
using MicroSeconds = Duration<i64, Micro>;
using MilliSeconds = Duration<i64, Milli>;
using Seconds = Duration<i64, Unit>;
using Minutes = Duration<i64, Ratio<60>>;
using Hours = Duration<i64, Ratio<60 * 60>>;
using Days = Duration<i64, Ratio<60 * 60 * 24>>;
using Weeks = Duration<i64, Ratio<60 * 60 * 24 * 7>>;

using HighResClock = std::chrono::high_resolution_clock;
using SystemClock = std::chrono::system_clock;
using SteadyClock = std::chrono::steady_clock;
using SysClock = std::chrono::system_clock;
} // namespace betr

#endif
