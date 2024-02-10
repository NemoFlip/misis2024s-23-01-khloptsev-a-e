#include <stackarr/stackarr.hpp>
#include <stdexcept>
StackArr::StackArr() {
  data_ = new Complex[1];
  capacity_ = 1;
}
StackArr::StackArr(const StackArr& rhs): capacity_ {rhs.capacity_}, top_index { rhs.top_index } {
  data_ = new Complex[capacity_];
  for (std::ptrdiff_t i = 0; i < rhs.top_index; i += 1) {
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
}
void StackArr::Push(const Complex& element) {
  if (capacity_ > top_index) {
    top_index += 1;
    data_[top_index] = element;
  } else {
    Complex* temp_data = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_; i += 1) {
      temp_data[i] = data_[i];
    }
    delete[] data_;
    capacity_ += 1;
    data_ = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_ - 1; i += 1) {
      data_[i] = temp_data[i];
    }
    data_[capacity_] = element;
    top_index += 1;
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

const Complex& StackArr::Top() {
  if (top_index == - 1) {
    throw std::out_of_range("Trying to get top element from empty Stack");
  }
  return data_[top_index];
}

