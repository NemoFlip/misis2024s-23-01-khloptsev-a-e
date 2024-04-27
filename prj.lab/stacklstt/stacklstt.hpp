#ifndef StackLstTT_H
#define StackLstTT_H
#include <stdexcept>

template <class T>
class StackLstT {
public:
    [[nodiscard]] StackLstT() = default;
    [[nodiscard]] StackLstT(const StackLstT& rhs);
    StackLstT(StackLstT&& rhs) noexcept;
    StackLstT& operator=(StackLstT&& rhs) noexcept;
    StackLstT& operator=(const StackLstT& rhs);
    bool IsEmpty() const noexcept;
    void Push(const T& val);
    void Pop() noexcept;
    [[nodiscard]] const T& Top() const;
    [[nodiscard]] T& Top();
    void Clear() noexcept;
    ~StackLstT();
private:
    struct Node {
        T v;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};

template <class T>
bool StackLstT<T>::IsEmpty() const noexcept {
  return (head_ == nullptr);
}

template <class T>
void StackLstT<T>::Push(const T& val) {
  if (!IsEmpty()) {
    Node* temp = new Node;
    temp->v = val;
    temp->next = head_;
    head_ = temp;
  } else {
    head_ = new Node;
    head_->v = val;
  }
}

template <class T>
const T& StackLstT<T>::Top() const {
  if (this->IsEmpty()) {
    throw std::logic_error("StackLstT - try to get top from empty stack.");
  }
  return head_->v;
}

template <class T>
T& StackLstT<T>::Top() {
  if (this->IsEmpty()) {
    throw std::logic_error("StackLstT - try to get top from empty stack.");
  }
  return head_->v;
}

template <class T>
void StackLstT<T>::Clear() noexcept {
  Node* tmp = head_;
  while (tmp != nullptr) {
    head_ = head_->next;
    delete tmp;
    tmp = head_;
  }
}

template <class T>
StackLstT<T>::~StackLstT() {
  Clear();
}

template <class T>
void StackLstT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

template <class T>
StackLstT<T>::StackLstT(const StackLstT<T>& rhs) {
  if (!rhs.IsEmpty()) {
    Node* rhsTmp = rhs.head_;
    Node* lhsTmp = new Node;
    lhsTmp->v = rhsTmp->v;
    head_ = lhsTmp;
    rhsTmp = rhsTmp->next;
    while (rhsTmp != nullptr) {
      lhsTmp->next = new Node;
      lhsTmp->next->v = rhsTmp->v;
      rhsTmp = rhsTmp->next;
      lhsTmp = lhsTmp->next;
    }
  }
}

template <class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      Clear();
    } else {
      Node *rhsTmp = rhs.head_;
      if (IsEmpty()) {
        head_ = new Node{rhs.Top()};
      } else {
        head_->v = rhsTmp->v;
      }
      Node* lhsTmp = head_;
      rhsTmp = rhsTmp->next;
      while (rhsTmp != nullptr) {
        if (lhsTmp->next == nullptr) {
          lhsTmp->next = new Node;
        }
        lhsTmp->next->v = rhsTmp->v;
        rhsTmp = rhsTmp->next;
        lhsTmp = lhsTmp->next;
      }
      if (lhsTmp->next) {
        Node* tmp = lhsTmp->next->next; // второй после текущего элемент
        delete lhsTmp->next;
        lhsTmp->next = nullptr;
        lhsTmp = tmp; // переходим в элемент через один от текущего
        while (lhsTmp) {
          tmp = lhsTmp->next;
          delete lhsTmp;
          lhsTmp = tmp;
        }
      }
    }
  }
  return *this;
}

template <class T>
StackLstT<T>::StackLstT(StackLstT<T>&& rhs) noexcept {
  std::swap(head_, rhs.head_);
}

template <class T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
  }
  return *this;
}

#endif