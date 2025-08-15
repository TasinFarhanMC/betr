#ifndef BETR_FORMAT_HPP
#define BETR_FORMAT_HPP

#include <format>

namespace betr {
template <typename... args> using FormatString = std::format_string<args...>;
template <typename... args> using WFormatString = std::wformat_string<args...>;

} // namespace betr

#endif
