#ifndef DYNARR_H
#define DYNARR_H

#include <cstddef>

class DynArr {
public:
   [[nodiscard]] DynArr() = default;
   [[nodiscard]] DynArr(const DynArr& dynarr);
   [[nodiscard]] DynArr(const std::ptrdiff_t size);
   [[nodiscard]] DynArr& operator=(const DynArr& dynarr);
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
    std::ptrdiff_t capacity_ {1};
    float* data_ = new float[1];
};

#endif // !DYNARR_H
