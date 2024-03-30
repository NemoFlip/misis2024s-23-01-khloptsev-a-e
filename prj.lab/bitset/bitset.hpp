#ifndef BITSET_H
#define BITSET_H
#include <vector>
#include <cstdint>

class BitSet {
public:
    class BiA {
    public:
        BiA(BitSet& bst, const int32_t idx): bst_ { bst }, idx_ { idx } { }
        BiA& operator=(const bool val) {
          bst_.Set(idx_, val);
          return *this;
        }

    private:
        int32_t idx_ = 0;
        BitSet& bst_;
    };
public:
    BitSet() = default;
    explicit BitSet(int32_t size);
    BitSet(const BitSet& rhs) = default;
    BitSet(BitSet&& rhs) noexcept;
    BitSet& operator=(const BitSet& rhs) = default;
    BitSet& operator=(BitSet&& rhs) noexcept;
    ~BitSet() = default;
    [[nodiscard]] uint32_t Size() const noexcept;
    void Resize(const int32_t size);
    std::vector<uint32_t> Vec() {
      return data_;
    }
    void Set(const int32_t idx, const bool v);
    [[nodiscard]] bool Get(const int32_t idx) const;
    void Fill(const bool val);

    BiA operator[](const int32_t idx); // bst[5] = true;
private:
    std::vector<uint32_t> data_ { };
    std::int32_t size_ = 0;
};
BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);
BitSet operator~(const BitSet& lhs);
#endif