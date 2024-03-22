#include <bitset/bitset.hpp>

BitSet::BitSet(const uint32_t size): data_ { ((size - 1) / 32) + 1 }, size_ { size } {

}
BitSet::BitSet(const BitSet& rhs): data_ { rhs.data_ }, size_ { rhs.size_ } {

}
BitSet::BitSet(BitSet&& rhs) noexcept {
  std::swap(data_, rhs.data_);
  std::swap(size_, rhs.size_);
}
BitSet& BitSet::operator=(BitSet&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
  }
  return *this;
}
uint32_t BitSet::Size() const noexcept {
  return size_;
}
void BitSet::Resize(const uint32_t size) {
  uint32_t capcaity_ = (data_.size()) * 32;
  if (size > capcaity_) {
    uint32_t add_count = ((size - capcaity_) - 1) / 32 + 1;
    for (int i = 0; i < add_count; i += 1) {
      data_.push_back(0);
    }
  }
  size_ = size;
}
void BitSet::Set(const int32_t idx, const bool v) {
    // 00000000000000000111000000 >> 1;
}
bool BitSet::Get(const int32_t idx) const {

}


void BitSet::Fill(const bool val) {
  for (int i = 0; i < data_.size(); i += 1) {
    data_[i] = val ? UINT32_MAX : 0;
  }
}
BitSet operator&(const BitSet& lhs, const BitSet& rhs) {

}
BitSet operator|(const BitSet& lhs, const BitSet& rhs) {

}
BitSet operator^(const BitSet& lhs, const BitSet& rhs) {

}
BitSet operator~(const BitSet& lhs) {

}
