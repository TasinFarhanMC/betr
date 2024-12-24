#ifndef BETR_VECTOR_HPP
#define BETR_VECTOR_HPP

#include <vector>

namespace betr {
template <typename T, typename Alloc = std::allocator<T>> using Vector = std::vector<T, Alloc>;
} // namespace betr

#include "detail/using.hpp"

#endif
