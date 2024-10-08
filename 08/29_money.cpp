#include <iomanip>
#include <iostream>

using namespace std;

// ".5 of a cent rounds up, anything less than .5 rounds down"
long int round_cents(double d) {
  // quotient is number of cents in d
  // remainder is tenths of a cent in d
  const ldiv_t quotrem = div(
    static_cast<long int>(d * 1000),
    static_cast<long int>(10)
  );
  const long int thousandths = quotrem.rem;
  if (thousandths >= 5) {
    return quotrem.quot + 1;
  }
  return quotrem.quot;
}
class Money {
public:
  explicit Money(double amount) :
    cents{round_cents(amount)} {
  }
  [[nodiscard]]
  double amount() const {
    return static_cast<double>(cents / 100);
  }
  [[nodiscard]]
  pair<long int, long int> dollars_cents() const {
    const ldiv_t quotrem = div(cents, static_cast<long int>(100));
    return tie(quotrem.quot, quotrem.rem);
  }
private:
  long int cents;
};

Money operator+(const Money &m1, const Money& m2) {
  return Money(m1.amount() + m2.amount());
}
Money operator-(const Money &m1, const Money& m2) {
  return Money(m1.amount() - m2.amount());
}

Money operator*(double d, const Money& m) {
  return Money(d * m.amount());
}
Money operator*(const Money& m, double d) {
  return d * m;
}


ostream& operator<<(ostream& os, const Money& m) {
  const auto [dollars, cents] = m.dollars_cents();
  return os << '$' << dollars << '.' << (cents < 10 ? "0" : "") << cents << '\n';
}

int main() {
  double d;
  while (cin >> d) {
    cout << Money{d} << '\n';
  }
}
