#ifndef BETR_ATOMIC_HPP
#define BETR_ATOMIC_HPP

#include <atomic>

namespace betr {
template <typename T> using Atomic = std::atomic<T>;
using AtomicFlag = std::atomic_flag;
using AtomicBool = std::atomic_bool;
using AtomicChar = std::atomic_char;
using AtomicInt = std::atomic_int;
using AtomicUInt = std::atomic_uint;

using AtomicU8 = std::atomic_uint8_t;
using AtomicU16 = std::atomic_uint16_t;
using AtomicU32 = std::atomic_uint32_t;
using AtomicU64 = std::atomic_uint64_t;
using AtomicUMax = std::atomic_uint64_t;
using AtomicUSize = std::atomic_size_t;

using Atomic8 = std::atomic_int8_t;
using Atomic16 = std::atomic_int16_t;
using Atomic32 = std::atomic_int32_t;
using Atomic64 = std::atomic_int64_t;
using AtomicMax = std::atomic_int64_t;
using AtomicSize = std::atomic_ptrdiff_t;

#ifdef BETR_FUNCTIONAL_HPP
template <typename T> class AtomicSignal {
  AtomicFlag flag = false;
  Atomic<T> value;

public:
  void set(const T value) {

    AtomicBool b;
    flag.test_and_set();
    this->value.store(value, std::memory_order_release);
  }
  void set(const Function<T(const T)> mutate) {
    flag.test_and_set();
    value.store(mutate(value.load(std::memory_order_acquire)), std::memory_order_release);
  }

  void handle(const Function<void(const T)> handler) {
    if (flag.test_and_set(std::memory_order_acquire)) { handler(value.load(std::memory_order_acquire)); }
    flag.clear(std::memory_order_release);
  }

  AtomicSignal(const T value) { this->value.store(value, std::memory_order_release); }
};
#endif
} // namespace betr

#include "detail/using.hpp"

#endif
