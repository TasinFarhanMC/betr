#ifndef BETR_CHRONO_HPP
#define BETR_CHRONO_HPP

#include "ratio.hpp"
#include <chrono>

namespace betr {
using std::chrono::duration_cast;
using std::chrono::duration_values;
using std::chrono::time_point_cast;

template <typename T>
concept ClockType = requires { std::chrono::is_clock_v<T>; };

template <typename T, typename ratio> using Duration = std::chrono::duration<T, ratio>;
template <ClockType clock, typename duration = typename clock::duration> using TimePoint = std::chrono::time_point<clock, duration>;

template <typename T = i64> using NanoSeconds = Duration<T, Nano>;
template <typename T = i64> using MicroSeconds = Duration<T, Micro>;
template <typename T = i64> using MilliSeconds = Duration<T, Milli>;
template <typename T = i64> using Seconds = Duration<T, Scaler>;
template <typename T = i64> using Minutes = Duration<T, Ratio<60>>;
template <typename T = i64> using Hours = Duration<T, Ratio<60 * 60>>;
template <typename T = i64> using Days = Duration<T, Ratio<60 * 60 * 24>>;
template <typename T = i64> using Weeks = Duration<T, Ratio<60 * 60 * 24 * 7>>;
template <typename T = i64> using Months = Duration<T, std::chrono::months::period>;
template <typename T = i64> using Years = Duration<T, std::chrono::years::period>;

using HighResClock = std::chrono::high_resolution_clock;
using SystemClock = std::chrono::system_clock;
using SteadyClock = std::chrono::steady_clock;
using UTCClock = std::chrono::utc_clock;
using TAIClock = std::chrono::tai_clock;
using GPSClock = std::chrono::gps_clock;
} // namespace betr

#endif
