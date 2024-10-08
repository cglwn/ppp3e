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
  Date (Year y, Month m, int d);
private:
  Year y;
  Month m;
  int d;
};

Date::Date(Year y, Month m, int d) : y{y}, m{m}, d{d} {}


int main() {
  Month m = Month::oct;
  cout << ++m << '\n';
  cout << ++m << '\n';
  cout << ++m << '\n';
  cout << ++m << '\n';
  Date date{Year{1998}, Month::mar, 30};
}
