#include <vector>

namespace betr {
template <typename T, typename Alloc = std::allocator<T>> using Vector = std::vector<T, Alloc>;
}
