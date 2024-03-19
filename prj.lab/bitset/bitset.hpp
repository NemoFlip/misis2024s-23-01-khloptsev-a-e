#ifndef BITSET_H
#define BITSET_H
#include <vector>
#include <cstdint>

class BitSet {
public:
    BitSet() = default;
    BitSet(const int32_t);
    BitSet(const BitSet& rhs);
    BitSet(BitSet&& rhs) noexcept;
    BitSet& operator=(const BitSet& rhs);
    BitSet& operator=(BitSet&& rhs) noexcept;
    ~BitSet();
private:
    std::vector<uint32_t> data_ { };
};

#endif