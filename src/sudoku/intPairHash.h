#ifndef INTPAIRHASH_H
#define INTPAIRHASH_H
#include <utility>

//allows set operations to happen in an unordered set,
//nto designed to be cryptographically secure, instead designed for quick
//access of elements
struct IntPairHash {
    int operator()(const std::pair<int, int>& pair) const {
        return pair.first + 9 * pair.second;
    }
};


#endif
