#ifndef BETR_ARRAY_HPP
#define BETR_ARRAY_HPP

#include "def.hpp"
#include <array>

namespace betr {
template <typename T, usize size> using Array = std::array<T, size>;
} // namespace betr

#endif
