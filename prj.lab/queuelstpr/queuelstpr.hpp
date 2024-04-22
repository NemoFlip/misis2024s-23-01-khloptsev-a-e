#ifndef QUEUELSTPR_H
#define QUEUELSTPR_H
#include <cstddef>
class QueueLstPr {
public:
    QueueLstPr() = default;
    QueueLstPr(const QueueLstPr& rhs);
    QueueLstPr(QueueLstPr&& rhs) noexcept;
    QueueLstPr& operator=(const QueueLstPr& rhs);
    QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;
    bool IsEmpty() const noexcept;
    void Push(float val);
    void Pop() noexcept;
    const float& Top() const &;
    float& Top() &;
    void Clear() noexcept;
    ~QueueLstPr();
private:
    struct Node {
      float v = 0.0f;
      Node* next = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};
#endif