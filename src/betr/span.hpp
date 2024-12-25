#ifndef BETR_SPAN_HPP
#define BETR_SPAN_HPP

#include "def.hpp"
#include <span>

namespace betr {
template <typename T, usize extent> using InitList = std::span<T, extent>;
} // namespace betr

#endif
