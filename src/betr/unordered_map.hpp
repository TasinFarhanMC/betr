#ifndef BETR_UNORDERED_MAP_HPP
#define BETR_UNORDERED_MAP_HPP

#include <unordered_map>

namespace betr {
template <typename Key, typename Value> using UnorderedMap = std::unordered_map<Key, Value>;
}
#endif
