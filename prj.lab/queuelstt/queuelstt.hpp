#ifndef QueueLstT_H
#define QueueLstT_H
#include <stdexcept>

template <class T>
class QueueLstT {
public:
    QueueLstT() = default;
    QueueLstT(const QueueLstT& rhs);
    QueueLstT& operator=(const QueueLstT& rhs);
    QueueLstT& operator=(QueueLstT&& rhs) noexcept;
    QueueLstT(QueueLstT&& rhs) noexcept;
    bool IsEmpty() const noexcept;
    void Push(const T& val);
    void Pop() noexcept;
    [[nodiscard]] T& Top() &;
    [[nodiscard]] const T& Top() const &;
    void Clear() noexcept;
    ~QueueLstT();
private:
    struct Node {
        T v;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template <class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
  return head_ == nullptr;
}

template <class T>
void QueueLstT<T>::Push(const T &val) {
  if (!IsEmpty()) {
    Node *tmp = new Node;
    tmp->v = val;
    tail_->next = tmp;
    tail_ = tmp;
  } else {
    head_ = new Node;
    head_->v = val;
    tail_ = head_;
  }
}

template <class T>
void QueueLstT<T>::Pop() noexcept {
  if (!IsEmpty()) {

    if (head_ == tail_) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      Node *tmp = head_;
      head_ = head_->next;
      delete tmp;
    }

  }
}

template <class T>
T &QueueLstT<T>::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstT - try to get top value from empty queue");
  }
  return head_->v;
}

template <class T>
const T& QueueLstT<T>::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstT - try to get top value from empty queue");
  }
  return head_->v;
}

template <class T>
QueueLstT<T>::QueueLstT(const QueueLstT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node* lhsTmp = new Node;
    Node* rhsTmp = rhs.head_;
    head_ = lhsTmp;
    head_->v = rhsTmp->v;
    rhsTmp = rhsTmp->next;
    while (rhsTmp != nullptr) {
      lhsTmp->next = new Node;
      lhsTmp = lhsTmp->next;
      lhsTmp->v = rhsTmp->v;
      rhsTmp = rhsTmp->next;
    }
    tail_ = lhsTmp;
  }
}


template <class T>
void QueueLstT<T>::Clear() noexcept {
  Node* tmp = head_;
  while (tmp != nullptr) {
    head_ = head_->next;
    delete tmp;
    tmp = head_;
  }
  tail_ = nullptr;
}

template <class T>
QueueLstT<T>::~QueueLstT() {
  Clear();
}

template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node *lhsTmp = new Node;
    Node *rhsTmp = rhs.head_;
    head_ = lhsTmp;
    head_->v = rhsTmp->v;
    tail_ = head_;
    rhsTmp = rhsTmp->next;
    while (rhsTmp != nullptr) {
      lhsTmp->next = new Node;
      lhsTmp = lhsTmp->next;
      tail_ = lhsTmp;
      lhsTmp->v = rhsTmp->v;
      rhsTmp = rhsTmp->next;
    }
  }
  return *this;
}

template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.head_);
  }
  return *this;
}

template <class T>
QueueLstT<T>::QueueLstT(QueueLstT<T>&& rhs) noexcept {
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
}



#endif // !QueueLstT_H