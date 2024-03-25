#ifndef BITSET_H
#define BITSET_H
#include <vector>
#include <cstdint>

class BitSet {
public:
    BitSet() = default;
    explicit BitSet(uint32_t size);
    BitSet(const BitSet& rhs) = default;
    BitSet(BitSet&& rhs) noexcept;
    BitSet& operator=(const BitSet& rhs) = default;
    BitSet& operator=(BitSet&& rhs) noexcept;
    ~BitSet() = default;
    [[nodiscard]] uint32_t Size() const noexcept;
    void Resize(const uint32_t size);
    std::vector<uint32_t> Vec() {
      return data_;
    }
    void Set(const uint32_t idx, const bool v);
    [[nodiscard]] bool Get(const uint32_t idx) const;
    void Fill(const bool val);
private:
    std::vector<uint32_t> data_ { };
    uint32_t size_ = 0;
};
BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);
BitSet operator~(const BitSet& lhs);
#endif