#include <iostream>

using namespace std;

enum Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec,
};

enum Day {
  monday = 1
};

int bad_code(Month m) {
  if (m == 17) // 🐛 17th month
    return 0;
  if (m == monday) // 🐛 comparing Month to Day
    return 1;
  return 2;
}
int main() {
  Month m1 = feb;        // OK: feb in scope
  Month m2 = Month::feb; // also OK
#if false
  Month m3 = 7; // can't assign an int to a Month
#endif
  Month m4 = Month(7);   // OK: explicit conversion

  int x1 = m1;
}
