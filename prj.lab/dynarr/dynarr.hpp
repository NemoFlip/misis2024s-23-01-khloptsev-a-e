#ifndef DYNARR_H
#define DYNARR_H

#include <cstddef>

class DynArr {
public:
   [[nodiscard]] DynArr() = default;
   [[nodiscard]] DynArr(const DynArr& dynarr);
   DynArr(DynArr&& rhs) noexcept;
   [[nodiscard]] DynArr(const std::ptrdiff_t size);
   [[nodiscard]] DynArr& operator=(const DynArr& dynarr);
   DynArr& operator=(DynArr&& rhs) noexcept;
   ~DynArr() {
     delete[] data_;
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
