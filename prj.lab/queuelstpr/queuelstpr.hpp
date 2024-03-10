#ifndef QUEUELSTPR_H
#define QUEUELSTPR_H
#include <cstddef>
class QueueLstPr {
public:
    QueueLstPr() = default;
    QueueLstPr(const QueueLstPr& rhs);
    bool IsEmpty() const noexcept;
    void Push(float val);
    void Pop() noexcept;
    const float& Top() const;
    float& Top();

private:
    struct Node {
      float v = 0.0f;
      Node* next = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};
#endif