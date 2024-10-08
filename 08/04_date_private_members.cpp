#include <iostream>

using namespace std;

class Date {
public:
  Date (int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}
  void add_day(int n);
  int year() { return y; }
  int month() { return m; }
  int day() { return d; }
private:
  int y;
  int m;
  int d;
};

void Date::add_day(int n) {}

ostream& operator<<(ostream& os, Date d) {
  return os << d.year() << '/' << d.month() << '/' << d.day();
}

int main() {
  Date today{2024, 8, 9};
  cout << today << '\n';
}
