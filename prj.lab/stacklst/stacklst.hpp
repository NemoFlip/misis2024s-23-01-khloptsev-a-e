#ifndef STACKLST_HPP
#define STACKLST_HPP
#include <complex/complex.hpp>
class StackLst {
public:
    bool IsEmpty() const noexcept;
    void Push(const Complex& val);
    const Complex& Top() const;

private:
    struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};
#endif