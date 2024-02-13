#include <stackarr/stackarr.hpp>
#include <stdexcept>

StackArr::StackArr(const StackArr& rhs): capacity_ {rhs.capacity_}, top_index { rhs.top_index } {
  data_ = new Complex[rhs.capacity_];
  for (std::ptrdiff_t i = 0; i <= rhs.top_index; i += 1) {
    data_[i] = rhs.data_[i];
  }
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (capacity_ < rhs.capacity_) {
    delete[] data_;
    data_ = new Complex[rhs.capacity_];
    capacity_ = rhs.capacity_;
  }
  for (ptrdiff_t i = 0; i < capacity_; i += 1) {
    if (i <= rhs.top_index) {
      data_[i] = rhs.data_[i];
    } else {
      data_[i] = Complex(0.0);
    }
  }
  top_index = rhs.top_index;
  return *this;
}
void StackArr::Push(const Complex& val) {
  if (capacity_ == (top_index + 1) && capacity_ != 0) {
    Complex* temp_data = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_; i += 1) {
      temp_data[i] = data_[i];
    }
    delete[] data_;
    capacity_ *= 2;
    data_ = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_ / 2; i += 1) {
      data_[i] = temp_data[i];
    }
    delete[] temp_data;
    top_index += 1;
    data_[top_index] = val;
  } else if (capacity_ == 0 && top_index == -1) {
    capacity_ = (capacity_ + 1) * 2;
    data_ = new Complex[capacity_];
    top_index += 1;
    data_[top_index] = val;
  } else {
    top_index += 1;
    data_[top_index] = val;
  }
}

void StackArr::Pop() noexcept {
  if (top_index != -1) {
    data_[top_index] = Complex(0.0);
    top_index -= 1;
  }
}
bool StackArr::IsEmpty() const noexcept {
  return (top_index == -1);
}

const Complex& StackArr::Top() const {
  if (top_index == -1) {
    throw std::out_of_range("Trying to get top element from empty Stack");
  }
  return data_[top_index];
}

