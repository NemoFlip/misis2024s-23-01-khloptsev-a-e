#ifndef STACKLST_HPP
#define STACKLST_HPP
#include <complex/complex.hpp>
class StackLst {
public:
    bool IsEmpty() const noexcept;
    void Push(const Complex& val);
private:
    struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};
#endif