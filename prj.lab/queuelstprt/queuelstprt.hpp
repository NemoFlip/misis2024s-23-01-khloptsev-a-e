#ifndef QueueLstPrT_H
#define QueueLstPrT_H
#include <cstddef>
#include <stdexcept>

template <class T>
class QueueLstPrT {
public:
    QueueLstPrT() = default;
    QueueLstPrT(const QueueLstPrT& rhs);
    QueueLstPrT(QueueLstPrT&& rhs) noexcept;
    QueueLstPrT& operator=(const QueueLstPrT& rhs);
    QueueLstPrT& operator=(QueueLstPrT&& rhs) noexcept;
    bool IsEmpty() const noexcept;
    void Push(T val);
    void Pop() noexcept;
    const T& Top() const &;
    T& Top() &;
    void Clear() noexcept;
    ~QueueLstPrT();
private:
    struct Node {
        T v = 0.0f;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template <class T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node* rhs_tmp = rhs.head_;
    Push(rhs_tmp->v);
    rhs_tmp = rhs_tmp->next;
    while (rhs_tmp != nullptr) {
      Push(rhs_tmp->v);
      rhs_tmp = rhs_tmp->next;
    }
  } else {
    QueueLstPrT();
  }
}

template <class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept {
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
}

template <class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node* rhs_tmp = rhs.head_;
    Push(rhs_tmp->v);
    rhs_tmp = rhs_tmp->next;
    while (rhs_tmp != nullptr) {
      Push(rhs_tmp->v);
      rhs_tmp = rhs_tmp->next;
    }
  } else {
    QueueLstPrT();
  }
  return *this;
}

template <class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
  }
  return *this;
}

template <class T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

template <class T>
void QueueLstPrT<T>::Push(T val) {
  if (IsEmpty()) { // если очередь пустая
    head_ = new Node;
    head_->v = val;
    tail_ = head_;
  } else if (head_->next == nullptr) { // если в очереди один элемент
    if (head_->v > val) {
      Node* tmp = new Node;
      tmp->v = val;
      tmp->next = head_;
      head_ = tmp;
    } else {
      head_->next = new Node;
      head_->next->v = val;
      tail_ = head_->next;
    }
  } else { // если в очереди > 1 элемента
    Node* head_tmp = head_;
    Node* tmp = nullptr;
    while (head_tmp->next != nullptr) {
      if (head_tmp->v <= val && head_tmp->next->v >= val) { // если можем добавить элемент между другими
        tmp = head_tmp->next;
        head_tmp->next = new Node;
        head_tmp->next->v = val;
        head_tmp->next->next = tmp;
        break;
      }
      head_tmp = head_tmp->next;
    }
    if (tmp == nullptr) { // не добавили элемент между другими
      if (head_->v >= val) { // если новый элемент меньше минимального
        tmp = head_;
        head_ = new Node;
        head_->v = val;
        head_->next = tmp;
      } else if (tail_->v <= val) { // если новый элемент больше максимального
        tail_->next = new Node;
        tail_->next->v = val;
        tail_ = tail_->next;
      }
    }
  }

}

template <class T>
T& QueueLstPrT<T>::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPrT error - try to get top element from emptry queue");
  }
  return head_->v;
}

template <class T>
const T& QueueLstPrT<T>::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPrT error - try to get top element from emptry queue");
  }
  return head_->v;
}

template <class T>
void QueueLstPrT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_ == tail_) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      Node* tmp = head_;
      head_ = head_->next;
      delete tmp;
    }
  }
}

template <class T>
void QueueLstPrT<T>::Clear() noexcept {
  Node* tmp = head_;
  while (tmp != nullptr) {
    head_ = head_->next;
    delete tmp;
    tmp = head_;
  }
  tail_ = nullptr;
}

template <class T>
QueueLstPrT<T>::~QueueLstPrT() {
  Clear();
}

#endif