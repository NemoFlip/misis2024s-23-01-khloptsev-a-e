#ifndef BITSET_H
#define BITSET_H
#include <vector>
#include <cstdint>

class BitSet {
public:
    class BiA {
    public:
        BiA& operator=(const BiA& rhs) = default;
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
    explicit BitSet(const std::int32_t size);
    BitSet(const BitSet& rhs) = default;
    BitSet(BitSet&& rhs) noexcept;
    BitSet& operator=(const BitSet& rhs) = default;
    BitSet& operator=(BitSet&& rhs) noexcept;
    ~BitSet() = default;

    [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

    int32_t Size() const noexcept;
    void Resize(const int32_t size);

    void Set(const int32_t idx, const bool v);
    bool Get(const int32_t idx) const;

    void Fill(const bool val) noexcept;

    [[nodiscard]] BitSet& operator&=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator|=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator^=(const BitSet& rhs);
    [[nodiscard]] BitSet operator~();


    BiA operator[](const int32_t idx); // bst[5] = true;
private:
    std::vector<uint32_t> data_ { };
    std::int32_t size_ = 0;
};
BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);
#endif