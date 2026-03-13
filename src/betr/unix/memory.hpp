#ifndef BETR_UNIX_MEMORY_HPP
#define BETR_UNIX_MEMORY_HPP

#include <new>
#include <sys/mman.h>

namespace betr {
template <typename T> class PageAllocator {
public:
  using value_type = T;
  PageAllocator() noexcept = default;

  template <typename U> PageAllocator(const PageAllocator<U> &) noexcept {}

  T *allocate(std::size_t n) {
    if (n == 0) return nullptr;

    void *ptr = mmap(nullptr, n * sizeof(T), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) throw std::bad_alloc();

    return static_cast<T *>(ptr);
  }

  void deallocate(T *p, std::size_t n) noexcept {
    if (p) munmap(p, n * sizeof(T));
  }
};

template <typename T, typename U> bool operator==(const PageAllocator<T> &, const PageAllocator<U> &) { return true; }
template <typename T, typename U> bool operator!=(const PageAllocator<T> &a, const PageAllocator<U> &b) { return !(a == b); }
} // namespace betr

#endif
