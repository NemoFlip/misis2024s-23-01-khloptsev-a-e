#pragma once
#ifndef QueueArrT_H
#define QueueArrT_H
#include <cstddef>

template <class T>
class QueueArrT {
public:
    QueueArrT() = default;
    QueueArrT(const QueueArrT& rhs);
    QueueArrT(QueueArrT&& rhs) noexcept;
    QueueArrT& operator=(const QueueArrT& rhs);
    QueueArrT& operator=(QueueArrT&& rhs) noexcept;
    ~QueueArrT();
    void Push(const T& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] const T& Top() const &;
    [[nodiscard]] T& Top() &;
    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t head_index = -1; // индекс головы очереди
    std::ptrdiff_t tail_index = -1; // индекс хвоста очереди
    T* data_ = nullptr;
private:
    std::ptrdiff_t Count() const;
};
template <class T>
QueueArrT<T>::QueueArrT(const QueueArrT<T>& rhs): capacity_ {rhs.capacity_} {
  data_ = new T[rhs.capacity_];
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

template <class T>
QueueArrT<T>::QueueArrT(QueueArrT<T>&& rhs) noexcept {
  std::swap(head_index, rhs.head_index);
  std::swap(tail_index, rhs.tail_index);
  std::swap(data_, rhs.data_);
  std::swap(capacity_, rhs.capacity_);
}

template <class T>
QueueArrT<T>& QueueArrT<T>::operator=(QueueArrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_index, rhs.head_index);
    std::swap(tail_index, rhs.tail_index);
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
  }
  return *this;
}

template <class T>
std::ptrdiff_t QueueArrT<T>::Count() const {
  if (IsEmpty()) {
    return 0;
  } if (tail_index < head_index) {
    return (tail_index - head_index + capacity_ + 1);
  }
  return (tail_index - head_index + 1);
}

template <class T>
QueueArrT<T>& QueueArrT<T>::operator=(const QueueArrT<T>& rhs) {
  if (this != &rhs) {
    if (capacity_ < rhs.capacity_) {
      delete[] data_;
      data_ = new T[rhs.capacity_];
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

template <class T>
void QueueArrT<T>::Push(const T& val) {
  if (IsEmpty() && head_index == -1) {
    capacity_ = (capacity_ + 1) * 2;
    data_ = new T[capacity_];
    tail_index += 1;
    head_index += 1;
    data_[head_index] = val;
  } else if ((tail_index + 1) % capacity_ != head_index) { // есть место
    tail_index = (tail_index + 1) % capacity_;
    data_[tail_index] = val;
  } else { // нет места - надо выделять
    T* tmp = data_;
    data_ = new T[capacity_ * 2];
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

template <class T>
void QueueArrT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_index == tail_index) {
      head_index = -1;
      tail_index = -1;
    } else {
      head_index = (head_index + 1) % capacity_;
    }
  }
}

template <class T>
const T& QueueArrT<T>::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}

template <class T>
T& QueueArrT<T>::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("try to get top value from empty queue");
  }
  return data_[head_index];
}

template <class T>
bool QueueArrT<T>::IsEmpty() const noexcept {
  return (head_index < 0);
}

template <class T>
QueueArrT<T>::~QueueArrT() {
  delete[] data_;
}

template <class T>
void QueueArrT<T>::Clear() noexcept { // подразумеваем, что этот экземпляр мы еще будем использовать
  head_index = -1;
  tail_index = -1;
}


#endif