#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <complex/complex.hpp>
#include <cstddef>
class QueueArr {
public:
    QueueArr() = default;
    QueueArr(const QueueArr& rhs);
    ~QueueArr();
    void Push(const Complex& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    const Complex& Top() const;
    Complex& Top();

private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t size_ { 0 };
    std::ptrdiff_t head_index = -1; // индекс головы очереди
    std::ptrdiff_t tail_index = -1; // индекс хвоста очереди
    Complex* data_ = nullptr;

};

#endif