#ifndef STACKARR_H
#define STACKARR_H
#include <complex/complex.hpp>
#include <cstddef>
class StackArr {
public:
    [[nodiscard]] StackArr() = default;
    [[nodiscard]] StackArr(const StackArr& rhs);
    ~StackArr() {
      delete[] data_;
      data_ = nullptr;
    }
    [[nodiscard]] StackArr& operator=(const StackArr& rhs);
    void Push(const Complex& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] const Complex& Top() const;
    [[nodiscard]] Complex& Top();
    void Clear() noexcept;

private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t top_index = -1; // индекс верхнего элемента в стэке
    Complex* data_ = nullptr;
};
#endif // !STACKARR_H