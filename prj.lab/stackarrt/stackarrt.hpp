#ifndef StackArrT_H
#define StackArrT_H
#include <cstddef>
#include <stdexcept>

template <class T>
class StackArrT {
public:
    StackArrT() = default;
    StackArrT(const StackArrT& rhs);
    StackArrT(StackArrT&& rhs) noexcept;
    ~StackArrT() {
      delete[] data_;
      data_ = nullptr;
    }
    StackArrT& operator=(StackArrT&& rhs) noexcept;
    [[nodiscard]] StackArrT& operator=(const StackArrT& rhs);
    void Push(const T& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] const T& Top() const;
    [[nodiscard]] T& Top();
    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t top_index = -1; // индекс верхнего элемента в стэке
    T* data_ = nullptr;
};

template <class T>
StackArrT<T>::StackArrT(const StackArrT<T>& rhs): capacity_ {rhs.capacity_}, top_index { rhs.top_index } {
  data_ = new T[rhs.capacity_];
  for (std::ptrdiff_t i = 0; i <= rhs.top_index; i += 1) {
    data_[i] = rhs.data_[i];
  }
}
template <class T>
StackArrT<T>::StackArrT(StackArrT<T>&& rhs) noexcept {
  std::swap(top_index, rhs.top_index);
  std::swap(data_, rhs.data_);
  std::swap(capacity_, rhs.capacity_);
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(top_index, rhs.top_index);
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
  }
  return *this;
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) {
  if (this != &rhs) {
    if (capacity_ < rhs.capacity_) {
      delete[] data_;
      data_ = new T[rhs.capacity_];
      capacity_ = rhs.capacity_;
    }
    for (ptrdiff_t i = 0; i < capacity_; i += 1) {
      if (i <= rhs.top_index) {
        data_[i] = rhs.data_[i];
      } else {
        data_[i] = T(0.0);
      }
    }
    top_index = rhs.top_index;
  }
  return *this;
}

template <class T>
void StackArrT<T>::Push(const T& val) {
  if (capacity_ == (top_index + 1) && capacity_ != 0) {
    T* temp_data = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_; i += 1) {
      temp_data[i] = data_[i];
    }
    delete[] data_;
    capacity_ *= 2;
    data_ = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < capacity_ / 2; i += 1) {
      data_[i] = temp_data[i];
    }
    delete[] temp_data;
  } else if (capacity_ == 0 && top_index == -1) {
    capacity_ = (capacity_ + 1) * 2;
    data_ = new T[capacity_];
  }
  top_index += 1;
  data_[top_index] = val;
}

template <class T>
void StackArrT<T>::Pop() noexcept {
  if (top_index != -1) {
    data_[top_index] = T(0.0);
    top_index -= 1;
  }
}
template <class T>
bool StackArrT<T>::IsEmpty() const noexcept {
  return (top_index == -1);
}

template <class T>
const T& StackArrT<T>::Top() const {
  if (top_index == -1) {
    throw std::out_of_range("Trying to get top element from empty Stack");
  }
  return data_[top_index];
}
template <class T>
T& StackArrT<T>::Top() {
  if (top_index == -1) {
    throw std::out_of_range("Trying to get top element from empty Stack");
  }
  return data_[top_index];
}
template <class T>
void StackArrT<T>::Clear() noexcept {
  for (ptrdiff_t i = 0; i <= top_index; i += 1) {
    data_[i] = T(0.0);
  }
  top_index = -1;
}


#endif // !StackArrT_H