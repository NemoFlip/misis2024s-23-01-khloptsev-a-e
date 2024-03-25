#include <bitset/bitset.hpp>
#include <stdexcept>

BitSet::BitSet(const uint32_t size): data_ { ((size) / 32) + 1 }, size_ { size } {

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
  uint32_t capacity = (data_.size()) * 32;
  if (size > capacity) {
    uint32_t add_count = ((size - capacity) - 1) / 32 + 1;
    for (int i = 0; i < add_count; i += 1) {
      data_.push_back(0);
    }
  }
  size_ = size;
}
void BitSet::Set(const uint32_t idx, const bool v) {
  if (size_ <= idx) {
    throw std::out_of_range("Index in out of range");
  }
  uint32_t one_temp = 1; // 65(2) 31(31) 32(0)
  uint32_t data_index = data_.size() - 1 - (idx) / 32;
  one_temp = one_temp << (idx - 32 * (idx / 32));
  if (v) {
    data_[data_index] = data_[data_index] | one_temp;
  } else {
    one_temp = ~one_temp;
    data_[data_index] = data_index & one_temp;
  }
}


bool BitSet::Get(const uint32_t idx) const {
  uint32_t data_index = data_.size() - 1 - (idx) / 32;
  uint32_t curr_index = idx - 32 * (idx / 32);
  uint32_t one_temp = 1;
  one_temp = one_temp << curr_index;
  uint32_t result = one_temp & data_[data_index];
  return result == 1;
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
