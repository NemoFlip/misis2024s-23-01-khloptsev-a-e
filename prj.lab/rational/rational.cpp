#include <rational/rational.hpp>
Rational::Rational(const std::int64_t numer, const std::int64_t denom) : num_{numer}, den_{denom} {
  if (denom == 0) {
    throw std::invalid_argument("Division by zero");
  }
  if (denom < 0) {
    den_ = -den_;
    num_ = -num_;
  }
};
bool Rational::operator==(const Rational& rhs) const noexcept {
  std::int64_t firstDivisor = gcd(num_, den_);
  std::int64_t secondDivisor = gcd(rhs.num_, rhs.den_);
  return ((num_ / firstDivisor) == (rhs.num_ / secondDivisor)) && ((den_ / firstDivisor) == (rhs.den_ / secondDivisor));
}
bool Rational::operator<(const Rational& rhs) const noexcept {
  return (num_ * rhs.den_) < (rhs.num_ * den_);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
  return (num_ * rhs.den_) > (rhs.num_ * den_);
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
  return (num_ * rhs.den_) <= (rhs.num_ * den_);
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
  return (num_ * rhs.den_) >= (rhs.num_ * den_);
}
Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ *= rhs.den_;
  num_ += rhs.num_ * den_;
  den_ *= rhs.den_;
  std::int64_t divisor = gcd(num_, den_);
  num_ /= divisor;
  den_ /= divisor;
  return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  std::int64_t divisor = gcd(num_, den_);
  num_ /= divisor;
  den_ /= divisor;
  return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ *= rhs.den_;
  num_ -= rhs.num_ * den_;
  den_ *= rhs.den_;
  std::int64_t divisor = gcd(num_, den_);
  num_ /= divisor;
  den_ /= divisor;
  return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0) {
    throw std::runtime_error("Division by zero");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  std::int64_t divisor = gcd(num_, den_);
  num_ /= divisor;
  den_ /= divisor;
  return *this;
}
Rational& Rational::operator+=(const std::int64_t rhs) noexcept {
  return operator+=(Rational(rhs));
}
Rational& Rational::operator-=(const std::int64_t rhs) noexcept {
  return operator-=(Rational(rhs));
}
Rational& Rational::operator*=(const std::int64_t rhs) noexcept {
  return operator*=(Rational(rhs));
}
Rational& Rational::operator/=(const std::int64_t rhs) {
  return operator/=(Rational(rhs));
}
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  Rational tmp = Rational(lhs);
  tmp += rhs;
  return tmp;
}
Rational operator+(const Rational& lhs, const std::int64_t rhs) noexcept {
  Rational rhsd = Rational(rhs);
  return lhs + rhsd;
}
Rational operator+(const std::int64_t lhs, const Rational& rhs) noexcept {
  Rational lhsd = Rational(lhs);
  return lhsd + rhs;
}
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  Rational tmp = Rational(lhs);
  tmp -= rhs;
  return tmp;
}
Rational operator-(const Rational& lhs, const std::int64_t rhs) noexcept {
  Rational rhsd = Rational(rhs);
  return lhs - rhsd;
}
Rational operator-(const std::int64_t lhs, const Rational& rhs) noexcept {
  Rational lhsd = Rational(lhs);
  return lhsd - rhs;
}
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  Rational tmp = Rational(lhs);
  tmp *= rhs;
  return tmp;
}
Rational operator*(const Rational& lhs, const std::int64_t rhs) noexcept {
  Rational rhsd = Rational(rhs);
  return lhs * rhsd;
}
Rational operator*(const std::int64_t lhs, const Rational& rhs) noexcept {
  Rational lhsd = Rational(lhs);
  return lhsd * rhs;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational tmp = Rational(lhs);
  tmp /= rhs;
  return tmp;
}
Rational operator/(const Rational& lhs, const std::int64_t rhs) {
  Rational rhsd = Rational(rhs);
  return lhs / rhsd;
}

Rational operator/(const std::int64_t lhs, const Rational& rhs) {
  Rational lhsd = Rational(lhs);
  return lhsd / rhs;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
  std::int64_t numer = 0;
  char separator;
  std::int64_t denom = 1;
  istrm >> numer;
  istrm.get(separator);
  int64_t trash = istrm.peek();
  istrm >> denom;
  if (!istrm || trash > '9' || trash < '0') {
    istrm.setstate(std::ios_base::failbit);
  }
  if (istrm.good() || istrm.eof()) {
    if (separator == Rational::sep && den_ > 0) {
      num_ = numer;
      den_ = denom;
    }
  }
  return istrm;
}
std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
  return ostrm << num_ << sep << den_;
}
std::ostream& operator<<(std::ostream& os, const Rational& rhs) noexcept {
  return rhs.WriteTo(os);
}
std::istream& operator>>(std::istream& is, Rational& rhs) noexcept {
  return rhs.ReadFrom(is);
}