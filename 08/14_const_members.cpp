#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov ,dec
};

int to_int(Month m) {
  return static_cast<int>(m);
}

Month operator++(Month& m) {
  m = (m==Month::dec) ? Month::jan : Month{to_int(m) + 1};
  return m;
}

vector<string> month_tbl = {
  "Not a month",
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December",
};

ostream& operator<<(ostream& os, Month m) {
  return os << month_tbl[to_int(m)];
}

struct Year {
  int y;
};

class Date {
public:
  Date();
  Date (Year y, Month m, int d);

  // const member: can't modify the object
  int day() const;
  Month month() const;
  Year year() const;

  // non-const member: can modify the object
  void add_day(int n);

  friend ostream& operator<<(ostream& os, Date d);
private:
  Year y {2001};
  Month m = Month::jan;
  int d = 1;
};
Date::Date() {}
Date::Date(Year y, Month m, int d) : y{y}, m{m}, d{d} {}
ostream& operator<<(ostream& os, Date d) {
  return os << d.y.y << "/" << d.m << "/" << d.d;
}
int Date::day() const {
  return d;
}
Month Date::month() const {
  return m;
}
Year Date::year() const {
  return y;
}
void Date::add_day(int n) {
  ++d;
}

int main() {
  Date d;
  const Date start_of_term;

  int a = d.day();
  int b = start_of_term.day();

  d.add_day(3);
#if false
  // add_day is non-const so can't be called on a const Date
  start_of_term.add_day(3);
#endif
}
