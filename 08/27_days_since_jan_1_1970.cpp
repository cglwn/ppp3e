#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool leapyear(int year) {
  const bool div_by_4 = year%4 == 0;
  if (div_by_4) {
    const bool div_by_100 = (year % 100) == 0;
    const bool div_by_400 = (year % 400) == 0;
    if (div_by_100 && !div_by_400) {
      return false;
    }
    return true;
  }
  return false;
}

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
bool operator==(const Year& y1, const Year& y2) { return y1.y == y2.y; }

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
private:
  bool is_valid() const;
  long int d_ = 0;
};

Date::Date() = default;
Date::Date(Year y, Month m, int d) {
  if (!is_valid()) {
    throw runtime_error("invalid date");
  }

  d_ = 0;
  Year current_year{1970};
  Month current_month = Month::jan;
  int current_day = 1;
  while (current_year != y && current_month != m && current_day != d) {
    if (current_month == Month::dec && current_day == 31) {
      ++current_year.y;
      current_month = Month::jan;
      current_day = 1;
    } else if (current_day == days_in_month[to_int(current_month)]) {
      ++current_month;
      current_day = 1;
    } else {
      ++current_day;
    }
    ++d_;
  }
}
ostream& operator<<(ostream& os, Date d) {
  return os << d.year().y << "/" << d.month() << "/" << d.day();
}
int Date::day() const {
  int d = d_;
  Year y{1970};
  while (d > 365) {
    if (leapyear(y.y)) {
      d -= 366;
    } else {
      d -= 365;
    }
    ++y.y;
  }

  Month m{Month::jan};
  if (d > days_in_month[to_int(m)]) {
    d -= days_in_month[to_int(m)];
    ++m;
  }
  return d + 1;
}
Month Date::month() const {
  int d = d_;
  Year y{1970};
  while (d > 365) {
    if (leapyear(y.y)) {
      d -= 366;
    } else {
      d -= 365;
    }
    ++y.y;
  }

  Month m{Month::jan};
  if (d > days_in_month[to_int(m)]) {
    d -= days_in_month[to_int(m)];
    ++m;
  }
  return m;
}
Year Date::year() const {
  int d = d_;
  Year y{1970};
  while (d > 365) {
    if (leapyear(y.y)) {
      d -= 366;
    } else {
      d -= 365;
    }
    ++y.y;
  }
  return y;
}

void Date::add_day(int n) {
  ++d_;
}

bool Date::is_valid() const {
  return d_ >= 0;
}

int main() {
  Date today{Year{1970}, Month::jan, 28};
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "today=" << today << ", tomorrow=" << tomorrow << '\n';
}
