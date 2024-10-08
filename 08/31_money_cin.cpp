#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

enum class Currency {
  usd = 1,
  cad = 2,
  dkk = 3,
};
unordered_map<Currency, string> currency_string{
  {Currency::usd, "USD"},
  {Currency::cad, "CAD"},
  {Currency::dkk, "DKK"},
};
ostream& operator<<(ostream& os, Currency currency) {
  return os << currency_string[currency];
}

// ".5 of a cent rounds up, anything less than .5 rounds down"
double round_cents(double d) {
  // quotient is number of cents in d
  // remainder is tenths of a cent in d
  const ldiv_t quotrem = div(
    static_cast<long int>(d * 1000),
    static_cast<long int>(10)
  );
  const long int thousandths = quotrem.rem;
  long int cents = -1;
  if (thousandths >= 5) {
    cents = quotrem.quot + 1;
  } else {
    cents = quotrem.quot;
  }
  return (double)cents / (double)100;
}
class Money {
public:
  explicit Money(Currency currency, double amount) :
    cents{static_cast<long int>(amount * 100)},
    currency_{currency} {
    // quotient is number of cents in d
    // remainder is tenths of a cent in d
    const ldiv_t quotrem = div(
      static_cast<long int>(amount * 1000),
      static_cast<long int>(10)
    );
    const long int thousandths = quotrem.rem;
    if (thousandths != 0) {
      throw runtime_error("cannot represent amount exactly as long int");
    }

  }
  [[nodiscard]]
  double amount() const {
    return static_cast<double>(cents) / 100;
  }
  [[nodiscard]]
  pair<long int, long int> dollars_cents() const {
    const ldiv_t quotrem = div(cents, static_cast<long int>(100));
    return tie(quotrem.quot, quotrem.rem);
  }
  Currency currency() const {
    return currency_;
  }
private:
  long int cents;
  Currency currency_;
};

Money operator+(const Money &m1, const Money& m2) {
  if (m1.currency() != m2.currency())
    throw runtime_error("tried to add different currencies");
  return Money(m1.currency(), m1.amount() + m2.amount());
}
Money operator-(const Money &m1, const Money& m2) {
  if (m1.currency() != m2.currency())
    throw runtime_error("tried to subtract different currencies");
  return Money(m1.currency(), m1.amount() - m2.amount());
}

Money operator*(double d, const Money& m) {
  return Money{
    m.currency(),
    static_cast<double>(round_cents(d * m.amount()))
  };
}
Money operator*(const Money& m, double d) {
  return d * m;
}


ostream& operator<<(ostream& os, const Money& m) {
  const auto [dollars, cents] = m.dollars_cents();
  return os << m.currency() << dollars << '.' << (cents < 10 ? "0" : "") << cents;
}
istream& operator>>(istream& is, Money& m) {
  string s;
  is >> s;
  double amount;
  int i = 0;
  string currency;
  while (i < s.size() && !isdigit(s.at(i))) {
    currency += s.at(i);
    ++i;
  }
  if (i == s.size()) {
    is >> amount;
  } else {
    istringstream iss{s.substr(i, s.size() - i)};
    iss >> amount;
  }
  if (currency == "USD")
    m = Money(Currency::usd, amount);
  else if (currency == "CAD")
    m = Money(Currency::cad, amount);
  else if (currency == "DKK")
    m = Money(Currency::dkk, amount);
  else throw runtime_error("unknown currency");
  return is;
}

// Give an example of a calculation where a Rational gives a mathematically better result than
// Money.
//   Rational more accurate than money for 1/10000 + 1/10000
// Give an example of a calculation where a Rational gives a mathematically better result than
// double.
//  1/10 + 2/10 == 3/10 with Rational but 0.1 + 0.2 != 0.3 with doubles.
int main() {
  Money m{Currency::cad, 1.0};
  while (cin >> m) {
    cout << m << '\n';
  }
}
