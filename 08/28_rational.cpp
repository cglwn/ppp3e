// Rational class to work with fractions without losing precision.
#include <numeric>
#include <iostream>

using namespace std;

class Rational {
public:
  Rational(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator} {
    if (denominator == 0) {
      throw runtime_error("bad denominator, must be non-zero");
    }
  }

  [[nodiscard]] int n() const { return numerator_; }
  [[nodiscard]] int d() const { return denominator_; }
  operator double() {
    return static_cast<double>(numerator_) / denominator_;
  }
private:
  const int numerator_;
  const int denominator_;
};

ostream& operator<<(ostream& os, const Rational& r) {
  return os << r.n() << "/" << r.d();
}

Rational operator-(const Rational& r) {
  return Rational{-r.n(), r.d()};
}
Rational operator+(const Rational& r1, const Rational& r2) {
  const int denominator = lcm(r1.d(), r2.d());
  const int n1 = r1.n() * denominator / r1.d();
  const int n2 = r2.n() * denominator / r2.d();
  const int numerator = n1 + n2;
  const int gcd = std::gcd(numerator, denominator);
  return Rational{numerator/gcd, denominator/gcd};
}
Rational operator-(const Rational& r1, const Rational& r2) {
  return r1 + (-r2);
}
Rational operator*(const Rational& r1, const Rational& r2) {
  return Rational{
    r1.n() * r2.n(),
    r1.d() * r2.d()
  };
}
Rational operator/(const Rational& r1, const Rational& r2) {
  return r1 * Rational{r2.d(), r2.n()};
}

Rational operator*(const Rational& r, int i) {
  return Rational{r.n() * i, r.d()};
}
Rational operator*(int i, const Rational& r) {
  return Rational{r.n() * i, r.d()};
}
Rational simplify(const Rational& r) {
  const int gcd = std::gcd(r.n(), r.d());
  return Rational{r.n() / gcd, r.d() / gcd};
}
bool operator==(const Rational& r1, const Rational& r2) {
  const Rational s1 = simplify(r1);
  const Rational s2 = simplify(r2);
  return s1.n() == s2.n() && s1.d() == s2.d();
}

int main() {
  Rational r{2, 10'000};
  cout <<  "1/10 + 2/10 == 3/10 " << boolalpha << (Rational{1, 10} + Rational{2, 10} == Rational{3, 10}) << '\n';
  cout << "(0.1 + 0.2 == 0.3) " << boolalpha << (0.1 + 0.2 == 0.3) << '\n';
}
