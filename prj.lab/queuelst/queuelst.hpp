#ifndef QUEUELST_H
#define QUEUELST_H
#include <complex/complex.hpp>
class QueueLst {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& rhs);
    QueueLst& operator=(const QueueLst& rhs);
    bool IsEmpty() const noexcept;
    void Push(const Complex& val);
    void Pop() noexcept;
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;
    ~QueueLst();
private:
    struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif // !QUEUELST_H