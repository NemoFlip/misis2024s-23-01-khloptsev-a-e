#ifndef STACKARR_H
#define STACKARR_H
#include <complex/complex.hpp>
#include <cstddef>
class StackArr {
public:
    [[nodiscard]] StackArr();
    [[nodiscard]] StackArr(const StackArr& rhs);
    ~StackArr() {
      delete[] data_;
      data_ = nullptr;
    }
    [[nodiscard]] StackArr& operator=(const StackArr& rhs);
    void Push(const Complex& val);
    void Pop() noexcept;
    std::ptrdiff_t GetTopIndex() const noexcept {
      return top_index;
    }
    bool IsEmpty() const noexcept;
    [[nodiscard]] const Complex& Top() const;
private:
    std::ptrdiff_t capacity_ { 0 };
    std::ptrdiff_t top_index = -1; // индекс верхнего элемента в стэке
    Complex* data_ = nullptr;
};
#endif // !STACKARR_H