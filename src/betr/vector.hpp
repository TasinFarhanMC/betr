#ifndef BETR_VECTOR_HPP
#define BETR_VECTOR_HPP

#include "def.hpp"
#include <vector>

namespace betr {
template <typename T, typename Alloc = std::allocator<T>> using Vector = std::vector<T, Alloc>;
} // namespace betr

#endif
