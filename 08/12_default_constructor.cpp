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
  friend ostream& operator<<(ostream& os, Date d);
private:
  Year y;
  Month m;
  int d;
};
Date::Date() : y{Year{2001}}, m{Month::jan}, d{1} {}
Date::Date(Year y, Month m, int d) : y{y}, m{m}, d{d} {}
ostream& operator<<(ostream& os, Date d) {
  return os << d.y.y << "/" << d.m << "/" << d.d;
}


int main() {
  Date date;
  cout << date << '\n';
}
