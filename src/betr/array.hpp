#ifndef BETR_ARRAY_HPP
#define BETR_ARRAY_HPP

#include <array>

namespace betr {
template <typename T, std::size_t size> using Array = std::array<T, size>;
} // namespace betr

#endif
