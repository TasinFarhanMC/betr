#ifndef BETR_FUNCTIONAL_HPP
#define BETR_FUNCTIONAL_HPP

#include "def.hpp"
#include <functional>

namespace betr {
template <typename Signature> using Function = std::function<Signature>;
} // namespace betr

#endif
