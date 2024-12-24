#ifndef BETR_THREAD_HPP
#define BETR_THREAD_HPP

#include <thread>

namespace betr {
using Thread = std::thread;
namespace this_thread = std::this_thread;
} // namespace betr

#include "detail/using.hpp"

#endif
