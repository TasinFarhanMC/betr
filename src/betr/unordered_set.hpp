#ifndef BETR_UNORDERED_SET_HPP
#define BETR_UNORDERED_SET_HPP

#include <unordered_set>

namespace betr {
template <typename Key, typename Value> using UnorderedSet = std::unordered_set<Key, Value>;
}
#endif
