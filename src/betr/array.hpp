#ifndef BETR_ARRAY_HPP
#define BETR_ARRAY_HPP

#include <array>

namespace betr {
using usize = std::size_t;

template <typename T, usize size> using Array = std::array<T, size>;
} // namespace betr

#include "detail/using.hpp"

#endif
