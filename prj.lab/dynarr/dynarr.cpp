#include <dynarr/dynarr.hpp>
#include <stdexcept>

DynArr::DynArr(const DynArr& dynarr): size_{dynarr.size_}, capacity_{dynarr.capacity_}, data_{new float[capacity_]} {
  for (std::ptrdiff_t i = 0; i < dynarr.capacity_; i += 1) {
    data_[i] = dynarr.data_[i];
  }
}
DynArr::DynArr(DynArr&& rhs) noexcept {
  std::swap(size_, rhs.size_);
  std::swap(capacity_, rhs.capacity_);
  std::swap(data_, rhs.data_);
}
DynArr& DynArr::operator=(DynArr&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(size_, rhs.size_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(data_, rhs.data_);
  }
  return *this;
}

DynArr::DynArr(const std::ptrdiff_t size): size_{ size }, capacity_{ size } {
  if (size < 0) {
    throw std::invalid_argument("Negative size of DynArr");
  }
  data_ = new float[capacity_];
  for (std::ptrdiff_t i = 0; i < capacity_; i += 1) {
    data_[i] = 0.0f;
  }
}
 const float& DynArr::operator[](const std::ptrdiff_t idx) const {
  if (idx >= size_) {
    throw std::out_of_range("Index is out of range");
  }
  if (idx < 0) {
    throw std::invalid_argument("Negative index");
  }
  return data_[idx];
}
float& DynArr::operator[](const std::ptrdiff_t idx) {
  if (idx >= size_) {
    throw std::out_of_range("Index is out of range");
  }
  if (idx < 0) {
    throw std::invalid_argument("Negative index");
  }
  return data_[idx];
}

DynArr& DynArr::operator=(const DynArr& dynarr) {
  if (capacity_ >= dynarr.size_) {
    for (ptrdiff_t i = 0; i < dynarr.size_; i += 1) {
      data_[i] = dynarr.data_[i];
    }
  } else {
    delete[] data_;
    data_ = new float[dynarr.size_];
    for (ptrdiff_t i = 0; i < dynarr.size_; i += 1) {
      data_[i] = dynarr.data_[i];
    }
    capacity_ = size_;
  }
  size_ = dynarr.size_;
  return *this;
}
void DynArr::Resize(const std::ptrdiff_t size) {
  if (size < 0) {
    throw std::invalid_argument("Trying to resize by negative size");
  }
  if (size > capacity_) {
    float* dataTemp = new float[size_];
    for (std::ptrdiff_t i = 0; i < size_; i += 1) {
      dataTemp[i] = data_[i];
    }
    delete[] data_;
    data_ = new float[size];
    for (std::ptrdiff_t i = 0; i < size; i += 1) {
      if (i < size_) {
        data_[i] = dataTemp[i];
      } else {
        data_[i] = 0.0f;
      }
    }
    delete[] dataTemp;
    capacity_ = size;
  } else {
    for (std::ptrdiff_t i = size_; i < size; i += 1) {
      data_[i] = 0.0f;
    }
  }
  size_ = size;
}

