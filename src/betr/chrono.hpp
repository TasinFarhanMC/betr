#ifndef BETR_CHRONO_HPP
#define BETR_CHRONO_HPP

#include "ratio.hpp"
#include <chrono>

namespace betr {
using std::chrono::duration_cast;
using std::chrono::duration_values;
using std::chrono::time_point_cast;

template <typename T> concept ClockType = requires { std::chrono::is_clock_v<T>; };
template <ClockType clock, typename duration = typename clock::duration> using TimePoint = std::chrono::time_point<clock, duration>;

template <typename T, typename ratio> using Duration = std::chrono::duration<T, ratio>;

using NanoSeconds = Duration<i64, Nano>;
using MicroSeconds = Duration<i64, Micro>;
using MilliSeconds = Duration<i64, Milli>;
using Seconds = Duration<i64, Ratio<1>>;
using Minutes = Duration<i64, Ratio<60>>;
using Hours = Duration<i64, Ratio<60 * 60>>;
using Days = Duration<i64, Ratio<60 * 60 * 24>>;
using Weeks = Duration<i64, Ratio<60 * 60 * 24 * 7>>;
using Months = Duration<i64, std::chrono::months::period>;
using Years = Duration<i64, std::chrono::years::period>;

using HighResClock = std::chrono::high_resolution_clock;
using SystemClock = std::chrono::system_clock;
using SteadyClock = std::chrono::steady_clock;
using FileClock = std::chrono::file_clock;
using SysClock = std::chrono::system_clock;
using UtcClock = std::chrono::utc_clock;
using TaiClock = std::chrono::tai_clock;
using GpsClock = std::chrono::gps_clock;
} // namespace betr

#endif
