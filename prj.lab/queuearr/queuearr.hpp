#pragma once
#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <complex/complex.hpp>
#include <cstddef>
class QueueArr {
public:
    QueueArr() = default;
    QueueArr(const QueueArr& rhs);
    QueueArr(QueueArr&& rhs) noexcept;
    QueueArr& operator=(const QueueArr& rhs);
    QueueArr& operator=(QueueArr&& rhs) noexcept;
    ~QueueArr();
    void Push(const Complex& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] const Complex& Top() const &;
    [[nodiscard]] Complex& Top() &;
    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t head_index = -1; // индекс головы очереди
    std::ptrdiff_t tail_index = -1; // индекс хвоста очереди
    Complex* data_ = nullptr;
private:
    std::ptrdiff_t Count() const;
};

#endif