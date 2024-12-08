#ifndef BETR_INIT_LIST_HPP
#define BETR_INIT_LIST_HPP

#include <stddef.h>

namespace betr {
template <typename T> class InitList {
public:
  using TReference = T &;
  using TConstReference = const T &;
  using TIterator = T *;
  using TConstIterator = const T *;

private:
  TIterator array;
  size_t len;

public:
  constexpr InitList() noexcept : array(0), len(0) {}
  constexpr size_t size() const noexcept { return len; }

  constexpr TConstIterator begin() const noexcept { return array; }
  constexpr TConstIterator end() const noexcept { return begin() + size(); }
};

template <class _Tp> constexpr const _Tp *begin(InitList<_Tp> __ils) noexcept {
  return __ils.begin();
}

template <class _Tp> constexpr const _Tp *end(InitList<_Tp> __ils) noexcept {
  return __ils.end();
}
} // namespace betr

#endif
