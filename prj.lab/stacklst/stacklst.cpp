#include <stacklst/stacklst.hpp>
#include <stdexcept>
#include <vector>
bool StackLst::IsEmpty() const noexcept {
  return (head_ == nullptr);
}
void StackLst::Push(const Complex& val) {
  if (!(this->IsEmpty())) {
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

void StackLst::Pop() noexcept {
  if (!(this->IsEmpty())) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}
StackLst::StackLst(const StackLst& rhs) {
  if (!rhs.IsEmpty()) {
    Node *tmp = rhs.head_;
    Node *secondTmp = new Node;
    secondTmp->v = tmp->v;
    head_ = secondTmp;
    tmp = tmp->next;
    while (tmp != nullptr) {
      secondTmp->next = new Node;
      secondTmp->next->v = tmp->v;
      tmp = tmp->next;
      secondTmp = secondTmp->next;
    }
  } else {
    StackLst();
  }
}
StackLst& StackLst::operator=(const StackLst& rhs) {
  if (!rhs.IsEmpty()) {
    Node *tmp = rhs.head_;
    Node *secondTmp = new Node;
    secondTmp->v = tmp->v;
    head_ = secondTmp;
    tmp = tmp->next;
    while (tmp != nullptr) {
      secondTmp->next = new Node;
      secondTmp->next->v = tmp->v;
      tmp = tmp->next;
      secondTmp = secondTmp->next;
    }
  } else {
    StackLst();
  }
  return *this;
}



