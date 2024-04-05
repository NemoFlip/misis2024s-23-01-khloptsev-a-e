#include <bitset/bitset.hpp>
#include <stdexcept>
// ctors and operator=
BitSet::BitSet(const std::int32_t size): data_(((size) / 32) + 1, 0), size_ { size } {
  if (size < 0) {
    throw std::invalid_argument("Trying to initialize with negative size.");
  }

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

bool BitSet::operator==(const BitSet& rhs) const noexcept {
  if (size_ != rhs.size_) {
    return false;
  }
  for (int i = 0; i < size_; i += 1) {
    if (Get(i) != rhs.Get(i)) {
      return false;
    }
  }
  return true;
}
bool BitSet::operator!=(const BitSet& rhs) const noexcept {
  return !(operator==(rhs));
}

// BitSet functionality
int32_t BitSet::Size() const noexcept {
  return size_;
}
void BitSet::Resize(const int32_t size) {
  if (size <= 0) {
    throw std::logic_error("try to resize with negative size");
  }
  uint32_t capacity = (data_.size()) * 32;
  if (size > capacity) {
    uint32_t add_count = ((size - capacity) - 1) / 32 + 1;
    for (int i = 0; i < add_count; i += 1) {
      data_.push_back(0);
    }
  }
  size_ = size;
}
void BitSet::Set(const int32_t idx, const bool v) {
  if (size_ <= idx) {
    throw std::out_of_range("Index in out of range");
  }
  uint32_t one_temp = 1;
  one_temp = one_temp << (idx % 32);
  uint32_t data_index = idx / 32; // in that block our bit for idx
  if (v) {
    data_[data_index] = data_[data_index] | one_temp;
  } else {
    one_temp = ~one_temp;
    data_[data_index] = data_index & one_temp;
  }
}

bool BitSet::Get(const int32_t idx) const {
  if (size_ <= idx) {
    throw std::logic_error("index is more than size.");
  }
  uint32_t current_block = data_[idx / 32]; // in that block our bit for idx
  uint32_t result = current_block & (1 << (idx % 32));
  return result != 0;
//  uint32_t data_index = data_.size() - 1 - (idx) / 32; // index of block in vector
//  uint32_t curr_index = idx - 32 * (idx / 32); // index inside a block in vector
//  uint32_t one_temp = 1;
//  one_temp = one_temp << curr_index;
//  uint32_t result = one_temp & data_[data_index];

//  return result == 1;
}

void BitSet::Fill(const bool val) noexcept {
  for (int i = 0; i < data_.size(); i += 1) {
    data_[i] = val ? UINT32_MAX : 0;
  }
}
BitSet::BiA BitSet::operator[](const int32_t idx) {
  BiA bia = BiA(*this, idx);
  return bia;
}
bool BitSet::operator[](const int32_t idx) const {
  return Get(idx);
}

// Binary operations operators
BitSet& BitSet::operator&=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i += 1) {
      Set(i, Get(i) & rhs.Get(i));
    }
  } else {
    throw std::logic_error("BitSet: sizes are not equal");
  }
  return *this;
}
BitSet& BitSet::operator|=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i += 1) {
      Set(i, Get(i) | rhs.Get(i));
    }
  } else {
    throw std::logic_error("BitSet: sizes are not equal");
  }
  return *this;
}
BitSet& BitSet::operator^=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i += 1) {
      Set(i, Get(i) ^ rhs.Get(i));
    }
  } else {
    throw std::logic_error("BitSet: sizes are not equal");
  }
  return *this;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
  BitSet temp_bst = lhs;
  temp_bst &= rhs;
  return temp_bst;
}
BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
  BitSet temp_bst = lhs;
  temp_bst |= rhs;
  return temp_bst;
}
BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
  BitSet temp_bst = lhs;
  temp_bst ^= rhs;
  return temp_bst;
}
BitSet BitSet::operator~() {
  for (int i = 0; i < size_; i += 1) {
    Set(i, ~Get(i));
  }
  return *this;
}



