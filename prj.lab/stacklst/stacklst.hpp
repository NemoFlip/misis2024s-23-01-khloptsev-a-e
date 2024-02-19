#ifndef STACKLST_HPP
#define STACKLST_HPP
#include <complex/complex.hpp>
#include <cstddef>

class StackLst {
public:
    [[nodiscard]] StackLst(const StackLst& rhs);
    [[nodiscard]] StackLst() = default;
    [[nodiscard]] StackLst& operator=(const StackLst& rhs);
    bool IsEmpty() const noexcept;
    void Push(const Complex& val);
    void Pop() noexcept;
    [[nodiscard]] const Complex& Top() const;
    [[nodiscard]] Complex& Top();
    void Clear() noexcept;
    ~StackLst();
private:
    struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};
#endif