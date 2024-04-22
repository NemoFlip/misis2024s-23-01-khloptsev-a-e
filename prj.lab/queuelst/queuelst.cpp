
#include <queuelst/queuelst.hpp>
#include <stdexcept>

bool QueueLst::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void QueueLst::Push(const Complex &val) {
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

void QueueLst::Pop() noexcept {
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

Complex &QueueLst::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("queuelst - try to get top value from empty queue");
  }
  return head_->v;
}

const Complex &QueueLst::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("queuelst - try to get top value from empty queue");
  }
  return head_->v;
}

QueueLst::QueueLst(const QueueLst &rhs) {
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


void QueueLst::Clear() noexcept {
  Node* tmp = head_;
  while (tmp != nullptr) {
    head_ = head_->next;
    delete tmp;
    tmp = head_;
  }
  tail_ = nullptr;
}
QueueLst::~QueueLst() {
  Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
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

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.head_);
  }
  return *this;
}
QueueLst::QueueLst(QueueLst&& rhs) noexcept {
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
}

