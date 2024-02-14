#include <stacklst/stacklst.hpp>

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