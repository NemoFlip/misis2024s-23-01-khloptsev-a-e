#ifndef COMPLEX_COMPLEX_HPP_20231113
#define COMPLEX_COMPLEX_HPP_20231113
#include <iostream>
#include <cmath>
#include <iosfwd>

struct Complex {
    double re{0.0};
    double im{0.0};
    [[nodiscard]] Complex() = default;
    [[nodiscard]] Complex(const Complex& rhs) = default;
    [[nodiscard]] Complex(const double real, const double imaginary): re{real}, im{imaginary} { };
    [[nodiscard]] explicit Complex(const double real): re{real} { }

    Complex& operator=(const Complex& rhs) {
      re = rhs.re;
      im = rhs.im;
      return *this;
    }
    ~Complex() = default;
    [[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
    [[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

    [[nodiscard]] bool operator==(const Complex& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Complex& rhs) const noexcept {
      return !(operator==(rhs));
    }
    // Объявление операторов
    [[nodiscard]] Complex operator-() const noexcept;
    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator+=(const double rhs) noexcept;
    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator-=(const double rhs) noexcept;
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    static const char leftBrace{ '{' };
    static const char rightBrace{ '}' };
    static const char separator{ ',' };
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);
std::ostream& operator<<(std::ostream& os, const Complex& complex);
std::istream& operator>>(std::istream& is, Complex& complex);
#endif