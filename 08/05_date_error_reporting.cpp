#include <iostream>

using namespace std;

class Date {
public:
  Date (int yy, int mm, int dd);
  void add_day(int n);
  int year() { return y; }
  int month() { return m; }
  int day() { return d; }
  class Invalid{};
private:
  int y;
  int m;
  int d;
  bool is_valid();
};

Date::Date(int yy, int mm, int dd): y{yy}, m{mm}, d{dd} {
  if (!is_valid())
    throw Invalid{};
}

bool Date::is_valid() {
  return 0 < m && m < 13;
}

void Date::add_day(int n) {}

ostream& operator<<(ostream& os, Date d) {
  return os << d.year() << '/' << d.month() << '/' << d.day();
}

void f(int x, int y)
try {
  Date dxy {2024, x, y};
  cout << dxy << '\n';
} catch(Date::Invalid) {
  throw runtime_error("f(): invalid date");
}

int main() {
  Date today{2024, 8, 9};
  cout << today << '\n';
}
