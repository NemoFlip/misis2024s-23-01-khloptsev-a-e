#include <queuearr/queuearr.hpp>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& rhs) {

}

void QueueArr::Push(const Complex& val) {
  if (IsEmpty()) {
    capacity_ = (capacity_ + 1) * 2;
    data_ = new Complex[capacity_];
    head_index += 1;
    tail_index += 1;
    data_[head_index] = val;
    size_ += 1;
  } else if (capacity_ == size_) {
    capacity_ = capacity_ * 2;
    Complex* tmp = new Complex[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_; i += 1) {
      if (i <= tail_index) {
        tmp[i] = data_[i];
      } else {
        tmp[i] = {0.0, 0.0};
      }
    }
    delete[] data_;
    data_ = tmp;
    tail_index += 1;
    data_[tail_index] = val;
    size_ += 1;
  } else {
    tail_index += 1;
    data_[tail_index] = val;
    size_ += 1;
  }
}
void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    head_index += 1;
    size_ -= 1;
  }
}
const Complex& QueueArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}
Complex& QueueArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}

bool QueueArr::IsEmpty() const noexcept {
  return (size_ == 0);
}
QueueArr::~QueueArr() {
  delete[] data_;
}