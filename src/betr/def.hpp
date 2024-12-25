#ifndef BETR_DEF_HPP
#define BETR_DEF_HPP

#include <stddef.h>
#include <stdint.h>

namespace betr {
using uint = unsigned int;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;
using imax = intmax_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using umax = uintmax_t;
} // namespace betr

#ifdef BETR_NAMESPACE_HPP
#define size_of(type)           sizeof(type)
#define align_of(type)          alignof(type)
#define align_as(alignment)     alignas(alignment)
#define offset_of(type, member) offsetof(type, member)
#define declare_type(expr)      decltype(expr)

#define ternary(expr, true_expr, false_expr) ((expr) ? (true_expr) : (false_expr))
#endif

#endif
