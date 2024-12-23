#include "functional.hpp"
#include <atomic>

namespace betr {
template <typename T> using Atomic = std::atomic<T>;
using Flag = std::atomic_flag;

template <typename T> class Signal {
  Flag flag = false;
  Atomic<T> value;

public:
  void set(const T value) {
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

  Signal(const T value) { this->value.store(value, std::memory_order_release); }
};
} // namespace betr
