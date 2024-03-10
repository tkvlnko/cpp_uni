#include <iostream>
#include <numeric>

class Rational {
private:
  int num;
  int den;

public:
  Rational(int = 0, int = 1);
  Rational operator+(const Rational &);
  Rational operator+=(const Rational &);
  Rational operator-=(const Rational &);
  Rational operator*=(const Rational &);
  Rational operator/=(const Rational &);

  Rational operator++();
  Rational operator--();
  Rational operator++(int);
  Rational operator--(int);

  Rational operator-(const Rational &);
  Rational operator*(const Rational &);
  Rational operator/(const Rational &);

  bool operator==(const Rational &);
  bool operator!=(const Rational &);

  Rational operator+();
  Rational operator-();

  Rational normalize();
  double Num();
  double Den();

  friend std::ostream &operator<<(std::ostream &ss, const Rational &comp);
};

Rational::Rational(int num, int den) {
  this->num = num;
  this->den = den;
}

double Rational::Num() {
  Rational r = this->normalize();
  return r.num;
}

double Rational::Den() {
  Rational r = this->normalize();
  return r.den;
}

// unary -
Rational Rational::operator-() { return {-num, den}; }

// unary +
Rational Rational::operator+() { return {+num, den}; }

Rational Rational::operator+(const Rational &other) {
  int comDen = std::lcm(den, other.den);
  return {((num * comDen / den) + (other.num * comDen / other.den)), comDen};
}

Rational Rational::operator+=(const Rational &other) {
  *this = *this + other;
  return *this;
}

// int + rational
Rational operator+(int num, Rational &rational) { return rational + num; }

Rational Rational::operator-(const Rational &other) {
  int comDen = std::lcm(den, other.den);
  return {((num * comDen / den) - (other.num * comDen / other.den)), comDen};
}

Rational Rational::operator-=(const Rational &other) {
  *this = *this - other;
  return *this;
}

// int - rational
Rational operator-(int num, Rational &rational) { return (-(rational - num)); }

Rational Rational::operator*(const Rational &other) {
  return {num * other.num, den * other.den};
}

Rational Rational::operator*=(const Rational &other) {
  *this = *this * other;
  return *this;
}

// int * rational
Rational operator*(int i, Rational &other) { return (other * i); }

Rational Rational::operator/(const Rational &other) {
  return {num * other.den, den * other.num};
}

Rational Rational::operator/=(const Rational &other) {
  *this = *this / other;
  return *this;
}

// int / rational
Rational operator/(int i, Rational &other) { return (Rational{i, 1} / other); }

Rational Rational::normalize() {
  int gcd = std::gcd(num, den);
  return {num / gcd, den / gcd};
}

bool Rational::operator==(const Rational &other) {
  Rational r = other;
  return (this->normalize().num == (r.normalize()).num) &&
         (this->normalize().den == (r.normalize()).den);
}
bool Rational::operator!=(const Rational &other) {
  Rational r = other;
  return (this->normalize().num != (r.normalize()).num) ||
         (this->normalize().den != (r.normalize()).den);
}

Rational Rational::operator++() {
  *this = *this + 1;
  return *this;
}

Rational Rational::operator++(int) {
  *this = *this + 1;
  return *this;
}

Rational Rational::operator--() {
  *this = *this - 1;
  return *this;
}

Rational Rational::operator--(int) {
  *this = *this - 1;
  return *this;
}

std::ostream &operator<<(std::ostream &ss, const Rational &r) {
  if (r.num == 0) {
    ss << 0;
  } else {
    ss << r.num << "/" << r.den;
  }
  return ss;
}

int main() {
  Rational r{1, 4};
  Rational p{1, 4};
  // std::cout << (p - 1);
  std::cout << (--p);
}