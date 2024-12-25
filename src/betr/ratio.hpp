#ifndef BETR_RATIO_HPP
#define BETR_RATIO_HPP

#include <ratio>

namespace betr {
using imax = intmax_t;

using std::ratio_add;
using std::ratio_subtract;

using std::ratio_divide;
using std::ratio_multiply;

template <typename T>
concept RatioType = requires {
  std::is_same_v<decltype(T::nom), imax>;
  std::is_same_v<decltype(T::den), imax>;
};

template <imax nominator, imax denominator = 1> using Ratio = std::ratio<nominator, denominator>;
template <RatioType ratio> using ratio_invert = Ratio<ratio::den, ratio::nom>;

template <RatioType a, RatioType b> constexpr bool ratio_greater = std::ratio_greater_v<a, b>;
template <RatioType a, RatioType b> constexpr bool ratio_equal = std::ratio_equal_v<a, b>;
template <RatioType a, RatioType b> constexpr bool ratio_less = std::ratio_less_v<a, b>;

template <RatioType a, RatioType b> constexpr bool ratio_not_equal = std::ratio_not_equal_v<a, b>;
template <RatioType a, RatioType b> constexpr bool ratio_greater_equal = std::ratio_greater_equal_v<a, b>;
template <RatioType a, RatioType b> constexpr bool ratio_less_equal = std::ratio_less_equal_v<a, b>;

using Femto = std::femto;
using Pico = std::pico;
using Nano = std::nano;
using Micro = std::micro;
using Milli = std::milli;
using Centi = std::centi;
using Deci = std::deci;
using Scaler = Ratio<1>;
using Deca = std::deca;
using Hecto = std::hecto;
using Kili = std::kilo;
using Mega = std::mega;
using Giga = std::giga;
using Tera = std::tera;
using Peta = std::peta;
using Exa = std::exa;

#if __INTMAX_WIDTH__ >= 128
using Quetta = std::quetta;
using Quecto = std::quecto;
#elif __INTMAX_WIDTH__ >= 96
using Ronto = std::ronto;
using Yocto = std::yocto;
using Zepto = std::zepto;

using Zetta = std::zetta;
using Yotta = std::yotta;
using Ronna = std::ronna;
#endif
} // namespace betr

#endif
