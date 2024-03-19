#include <stacklst/stacklst.hpp>
#include <stdexcept>
bool StackLst::IsEmpty() const noexcept {
  return (head_ == nullptr);
}
void StackLst::Push(const Complex& val) {
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
const Complex& StackLst::Top() const {
  if (this->IsEmpty()) {
    throw std::logic_error("StackLst - try to get top from empty stack.");
  }
  return head_->v;
}
Complex& StackLst::Top() {
  if (this->IsEmpty()) {
    throw std::logic_error("StackLst - try to get top from empty stack.");
  }
  return head_->v;
}
void StackLst::Clear() noexcept {
    Node* tmp = head_;
    while (tmp != nullptr) {
      head_ = head_->next;
      delete tmp;
      tmp = head_;
  }
}
StackLst::~StackLst() {
  Clear();
}


void StackLst::Pop() noexcept {
  if (!(this->IsEmpty())) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}
StackLst::StackLst(const StackLst& rhs) {
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
  } // deleted: else { StackLst(); }
}
StackLst& StackLst::operator=(const StackLst& rhs) {
  if (this != &rhs) {
    if (!rhs.IsEmpty()) {
      Node *rhsTmp = rhs.head_;
      Node *lhsTmp = new Node;
      lhsTmp->v = rhsTmp->v;
      head_ = lhsTmp;
      rhsTmp = rhsTmp->next;
      while (rhsTmp != nullptr) {
        lhsTmp->next = new Node;
        lhsTmp->next->v = rhsTmp->v;
        rhsTmp = rhsTmp->next;
        lhsTmp = lhsTmp->next;
      }
    } // deleted: else { StackLst(); }
  }
  return *this;
}
StackLst::StackLst(StackLst&& rhs) noexcept {
  std::swap(head_, rhs.head_);
}
StackLst& StackLst::operator=(StackLst&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(head_, rhs.head_);
  }
  return *this;
}



