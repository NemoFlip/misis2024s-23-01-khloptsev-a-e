#include <complex/complex.hpp>
#include <stdexcept>
#include <iostream>

[[nodiscard]] Complex Complex::operator-() const noexcept {
  Complex tmp;
  tmp.re = -re;
  tmp.im = -im;
  return tmp;
}
[[nodiscard]] bool Complex::operator==(const Complex& rhs) const noexcept {
  double delta = 2 * std::numeric_limits<double>::epsilon();
  bool re_differ = (std::abs(re - rhs.re) <= delta);
  bool im_differ = (std::abs(im - rhs.im) <= delta);
  return re_differ && im_differ;
}
Complex& Complex::operator+=(const Complex& rhs) noexcept {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept {
  Complex tmp{rhs};
  Complex::operator+=(tmp);
  return *this;
}
Complex& Complex::operator-=(const Complex& rhs) noexcept {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
  Complex tmp{rhs};
  Complex::operator-=(tmp);
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double real_result = (re * rhs.re - im * rhs.im);
  double imaginary_result = (re * rhs.im + im * rhs.re);
  re = real_result;
  im = imaginary_result;
  return *this;
}

Complex& Complex::operator*=(const double rhs) {
  Complex tmp{rhs};
  Complex::operator*=(tmp);
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  if (rhs == Complex{0.0,0.0}) {
    throw std::runtime_error("Division by zero");
  }
  double num_real = (re * rhs.re + im * rhs.im); // числитель действительной части
  double denom = ((rhs.re * rhs.re) + (rhs.im * rhs.im)); // знаменатель действительной и мнимой частей
  double real_result = num_real / denom;
  double num_im = (rhs.re * im - re * rhs.im); // числитель мнимой части
  double im_result = num_im / denom;
  re = real_result;
  im = im_result;
  return *this;
}

Complex& Complex::operator/=(const double rhs) {
  Complex tmp{rhs};
  *this /= tmp;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
  Complex ans = lhs;
  ans += rhs;
  return ans;
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
  Complex rhsd = Complex(rhs);
  return lhs + rhsd;
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
  Complex lhsd = Complex(lhs);
  return lhsd + rhs;
}
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
  Complex tmp = Complex(lhs);
  tmp -= rhs;
  return tmp;
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
  Complex tmp = Complex(rhs);
  return lhs - tmp;
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
  Complex lhsd = Complex(lhs);
  return lhsd - rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
  Complex tmp = Complex(lhs);
  tmp *= rhs;
  return tmp;
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
  Complex rhsd = Complex(rhs);
  return lhs * rhsd;
}

Complex operator*(const double lhs, const Complex& rhs) noexcept {
  Complex lhsd = Complex(lhs);
  return lhsd * rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex tmp = Complex(lhs);
  tmp /= rhs;
  return tmp;
}
Complex operator/(const Complex& lhs, const double rhs) {
  Complex rhsd = Complex(rhs);
  return lhs / rhsd;
}
Complex operator/(const double lhs, const Complex& rhs) {
  Complex lhsd = Complex(lhs);
  return lhsd / rhs;
}
std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
  return ostrm << Complex::leftBrace << re << Complex::separator << im << Complex::rightBrace;
}
std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
  return rhs.WriteTo(os);
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
  double real = 0;
  double imaginary = 0;
  char leftBrace, rightBrace, separator;
  istrm >> leftBrace >> real >> separator >> imaginary >> rightBrace;
  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == separator) && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
  }
}


std::istream& operator>>(std::istream& is, Complex& rhs) {
  return rhs.ReadFrom(is);
}