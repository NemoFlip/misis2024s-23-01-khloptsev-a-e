#ifndef DYNARR_H
#define DYNARR_H

#include <cstddef>

class DynArr {
public:
   DynArr(const DynArr& rhs);
   DynArr() = default;
   DynArr(DynArr&& rhs) noexcept;
   [[nodiscard]] DynArr(const std::ptrdiff_t size);
   [[nodiscard]] DynArr& operator=(const DynArr& dynarr);
   DynArr& operator=(DynArr&& rhs) noexcept;
   ~DynArr() {
     delete[] data_;
     data_ = nullptr;
   }
   void Resize(const std::ptrdiff_t size);
   [[nodiscard]] std::ptrdiff_t Size() const noexcept {
     return size_;
   }
   [[nodiscard]] float& operator[](const std::ptrdiff_t idx);
   [[nodiscard]] const float& operator[](const std::ptrdiff_t idx) const;
private:
    std::ptrdiff_t size_ {0};
    std::ptrdiff_t capacity_ {0};
    float* data_ = nullptr;
};

#endif // !DYNARR_H
