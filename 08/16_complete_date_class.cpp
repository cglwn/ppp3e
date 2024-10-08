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
vector<int> days_in_month = {
  -1,
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31,
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
  bool is_valid() const;
  Year y {2001};
  Month m = Month::jan;
  int d = 1;
};
Date::Date() = default;
Date::Date(Year y, Month m, int d) : y{y}, m{m}, d{d} {
  if (!is_valid()) {
    throw runtime_error("invalid date");
  }
}
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
  int new_day = d + 1;
  if (new_day > days_in_month[to_int(m)]) {
    d = 1;
    ++m;
  } else {
    d = new_day;
  }
}
bool Date::is_valid() const {
  return ((1 <= d) && (d <= 31)) &&
    ((1 <= to_int(m)) && (to_int(m) <= 12));
}

int main() {
  Date today{Year{2020}, Month::feb, 2};
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "today=" << today << ", tomorrow=" << tomorrow << '\n';
  try {
    Date bad_date{Year{2004}, Month{13}, -5};
    cout << bad_date << '\n';
  } catch (...) {
    cout << "Bad date caught\n";
  }
}
