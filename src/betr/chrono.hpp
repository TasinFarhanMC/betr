#ifndef BETR_CHRONO_HPP
#define BETR_CHRONO_HPP

#include "ratio.hpp"
#include <chrono>

namespace betr {
using std::chrono::duration_cast;
using std::chrono::duration_values;
using std::chrono::time_point_cast;

template <typename T, typename ratio> using Duration = std::chrono::duration<T, ratio>;
template <typename clock, typename duration = typename clock::duration> using TimePoint = std::chrono::time_point<clock, duration>;

template <typename T = i64> using NanoSecond = Duration<T, Nano>;
template <typename T = i64> using MicroSecond = Duration<T, Micro>;
template <typename T = i64> using MilliSecond = Duration<T, Milli>;
template <typename T = i64> using Second = Duration<T, Scaler>;
template <typename T = i64> using Minute = Duration<T, Ratio<60>>;
template <typename T = i64> using Hour = Duration<T, Ratio<60 * 60>>;
template <typename T = i64> using Day = Duration<T, Ratio<60 * 60 * 24>>;
template <typename T = i64> using Week = Duration<T, Ratio<60 * 60 * 24 * 7>>;

using HighResClock = std::chrono::high_resolution_clock;
using SystemClock = std::chrono::system_clock;
using SteadyClock = std::chrono::steady_clock;
} // namespace betr

#endif
