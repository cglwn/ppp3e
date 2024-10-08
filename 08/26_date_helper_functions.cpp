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


enum Day {
  Sun = 0,
  Mon ,
  Tue,
  Wed,
  Thur,
  Fri,
  Sat,
};

struct Year {
  int y;
};

class Date {
public:
  Date();
  Date (Year y, Month m, int d);

  int day() const;
  Month month() const;
  Year year() const;
  Day day_of_week() const;

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
Day Date::day_of_week() const {
  // Gauss' algorithm from https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Mathematical_algorithms
  // TODO: Currently off-by-1, the date for d1 = Jan/1/2024 is right but Aug/18/2024 returns Mon instead of Sun.
  int A = y.y;
  const div_t quotrem = div(A, 100);
  int C = quotrem.quot;
  int Y = quotrem.rem;

  int d1 = (1 + 5*((Y-1)%4) + 3*(Y-1) + 5*(C%4)) % 7;
  vector<int> month_offsets;
  if (leapyear(A)) {
    month_offsets = vector<int>{-1, 0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
  } else {
    month_offsets = vector<int>{-1, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  }
  const int month_offset = month_offsets[to_int(m)];
  return Day((d1 + month_offset + d) % 7);
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

Date next_workday(const Date& d) {
  Date next = d;
  next.add_day(1);
  while (next.day_of_week() == Day::Sat || next.day_of_week() == Day::Sun) {
    next.add_day(1);
  }
  return next;
}

int main() {
  Date today{Year{2024}, Month::aug, 15};
  Date next_workdate = next_workday(today);
  cout << "today=" << today.day_of_week() << ", next_workdate=" << next_workdate.day_of_week() << '\n';
}
