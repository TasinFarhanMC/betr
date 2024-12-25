#ifndef BETR_UNIX_MEMORY_HPP
#define BETR_UNIX_MEMORY_HPP

#include "../def.hpp"
#include <new>
#include <sys/mman.h>
#include <unistd.h>

namespace betr {
template <typename T> T *new_page(usize n, const T &val = T()) {
  if (n == 0) { return nullptr; }

  usize *bytes = reinterpret_cast<usize *>(mmap(nullptr, n * sizeof(T) + sizeof(usize), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
  if (bytes == MAP_FAILED) { throw std::bad_alloc(); }
  *bytes = n;

  T *data = reinterpret_cast<T *>(bytes + 1);
  for (usize i = 0; i < n; ++i) { new (data + i) T(val); }

  return data;
}

template <typename T> void delete_page(T *data) {
  usize *bytes = reinterpret_cast<usize *>(data) - 1;
  for (usize i = 0; i < *bytes; ++i) { data[i].~T(); }
  munmap(bytes, *bytes);
}

template <typename T> class PageAllocator {
public:
  using value_type = T;

  PageAllocator() noexcept {};

  T *allocate(usize n) {
    if (!n) { return nullptr; }

    T *data = static_cast<T *>(mmap(nullptr, n * sizeof(T), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (data == MAP_FAILED) { throw std::bad_alloc(); }

    return data;
  }

  void deallocate(T *data, usize n) {
    if (data) { munmap(data, n * sizeof(T)); }
  }
};
} // namespace betr

#endif
