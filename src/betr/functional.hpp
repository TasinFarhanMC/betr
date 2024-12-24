#ifndef BETR_FUNCTIONAL_HPP
#define BETR_FUNCTIONAL_HPP

#include <functional>

namespace betr {
using std::bind;

template <typename Signature> using Function = std::function<Signature>;
} // namespace betr

#include "detail/using.hpp"

#endif
