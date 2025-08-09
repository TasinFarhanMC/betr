#ifndef BETR_EXPECTED_HPP
#define BETR_EXPECTED_HPP

#include <expected>

namespace betr {
template <typename Value, typename Error> using Expected = std::expected<Value, Error>;
} // namespace betr

#endif
