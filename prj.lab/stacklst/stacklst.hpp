#ifndef STACKLST_HPP
#define STACKLST_HPP
#include <complex/complex.hpp>
class StackLst {
public:
    StackLst(const StackLst& rhs);
    StackLst() = default;
    bool IsEmpty() const noexcept;
    void Push(const Complex& val);
    const Complex& Top() const;
    void Pop() noexcept;
    StackLst& operator=(const StackLst& rhs);
//    ~StackLst();

private:
    struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};
#endif