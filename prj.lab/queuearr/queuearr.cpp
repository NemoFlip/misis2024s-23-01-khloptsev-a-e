#include <queuearr/queuearr.hpp>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& rhs): capacity_ {rhs.capacity_} {
  data_ = new Complex[rhs.capacity_];
  std::ptrdiff_t head_tmp = rhs.head_index;
  head_index = 0;
  tail_index = 0;
  data_[head_index] = rhs.data_[head_tmp];
  while (head_tmp != rhs.tail_index) {
    head_tmp = (head_tmp + 1) % capacity_;
    tail_index += 1;
    data_[tail_index] = rhs.data_[head_tmp];
  }
}
QueueArr::QueueArr(QueueArr&& rhs) noexcept {
  std::swap(head_index, rhs.head_index);
  std::swap(tail_index, rhs.tail_index);
  std::swap(data_, rhs.data_);
  std::swap(capacity_, rhs.capacity_);
}
QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_index, rhs.head_index);
    std::swap(tail_index, rhs.tail_index);
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
  }
  return *this;
}
std::ptrdiff_t QueueArr::Count() const {
  if (IsEmpty()) {
    return 0;
  } if (tail_index < head_index) {
    return (tail_index - head_index + capacity_ + 1);
  }
  return (tail_index - head_index + 1);
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
  if (this != &rhs) {
    if (capacity_ < rhs.capacity_) {
      delete[] data_;
      data_ = new Complex[rhs.capacity_];
      capacity_ = rhs.capacity_;
    }
    std::ptrdiff_t head_tmp = rhs.head_index;
    head_index = 0;
    tail_index = 0;
    data_[head_index] = rhs.data_[head_tmp];
    while (head_tmp != rhs.tail_index) {
      head_tmp = (head_tmp + 1) % capacity_;
      tail_index += 1;
      data_[tail_index] = rhs.data_[head_tmp];
    }
  }
  return *this;
}

void QueueArr::Push(const Complex& val) {
  if (IsEmpty() && head_index == -1) {
    capacity_ = (capacity_ + 1) * 2;
    data_ = new Complex[capacity_];
    tail_index += 1;
    head_index += 1;
    data_[head_index] = val;
  } else if ((tail_index + 1) % capacity_ != head_index) { // есть место
    tail_index = (tail_index + 1) % capacity_;
    data_[tail_index] = val;
  } else { // нет места - надо выделять
    Complex* tmp = data_;
    data_ = new Complex[capacity_ * 2];
    std::ptrdiff_t tmp_index = 0; // индекс для заполнения очереди уже добавленными элементами
    data_[tmp_index] = tmp[head_index];
    while (head_index != tail_index) {
      head_index = (head_index + 1) % capacity_;
      tmp_index += 1;
      data_[tmp_index] = tmp[head_index];
    }
    delete[] tmp;
    tmp_index += 1;
    data_[tmp_index] = val;
    head_index = 0;
    tail_index = tmp_index;
    capacity_ *= 2;
  }
}
void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_index == tail_index) {
      head_index = -1;
      tail_index = -1;
    } else {
      head_index = (head_index + 1) % capacity_;
    }
  }
}
const Complex& QueueArr::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}
Complex& QueueArr::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}

bool QueueArr::IsEmpty() const noexcept {
  return (head_index < 0);
}
QueueArr::~QueueArr() {
  delete[] data_;
}
void QueueArr::Clear() noexcept { // подразумеваем, что этот экземпляр мы еще будем использовать
  head_index = -1;
  tail_index = -1;
}