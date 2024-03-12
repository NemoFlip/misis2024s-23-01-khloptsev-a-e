#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <iosfwd>
class Rational {
public:
    // Конструкторы
    [[nodiscard]] Rational() = default;
    [[nodiscard]] Rational(const Rational& rhs) = default;
    [[nodiscard]] explicit Rational(const std::int64_t numer) noexcept: num_{numer} { };
    [[nodiscard]] Rational(const std::int64_t numer, const std::int64_t denom);
    [[nodiscard]] Rational& operator=(const Rational& rhs) = default;
    ~Rational() = default;
    // Методы
    [[nodiscard]] std::int64_t num() const noexcept { return num_; }
    [[nodiscard]] std::int64_t den() const noexcept { return den_; }
    std::istream& ReadFrom(std::istream& istrm);
    std::ostream& WriteTo(std::ostream& ostrm) const;
    // Операторы
    [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept {
      return !(operator==(rhs));
    }
    [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
    [[nodiscard]] Rational operator-() const noexcept { return {-num_, den_}; }
    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);

    Rational& operator+=(const std::int64_t rhs) noexcept;
    Rational& operator-=(const std::int64_t rhs) noexcept;
    Rational& operator*=(const std::int64_t rhs) noexcept;
    Rational& operator/=(const std::int64_t rhs);
private:
    static std::int64_t gcd(std::int64_t a, std::int64_t b) {
      a = std::abs(a);
      while (a != 0 && b != 0) {
        if (a > b) {
          a %= b;
        } else {
          b %= a;
        }
      }
      return (a + b);
    }
    static const char sep {'/'};
    std::int64_t num_ { 0 };
    std::int64_t den_ { 1 };
};
[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const std::int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const std::int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const std::int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const std::int64_t rhs);

[[nodiscard]] Rational operator+(const std::int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const std::int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const std::int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const std::int64_t lhs, const Rational& rhs);
std::ostream& operator<<(std::ostream& os, const Rational& rhs);
std::istream& operator>>(std::istream& is, const Rational rhs);
#endif