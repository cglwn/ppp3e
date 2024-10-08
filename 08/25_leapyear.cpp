#include <iostream>

using namespace std;

// "The rule is that if the year is divisible by 100 and not divisible by 400, leap year is skipped."
// https://airandspace.si.edu/stories/editorial/science-leap-year
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
int main() {
  cout << "leapyear(2024)=" << leapyear(2024) << '\n';
  cout << "leapyear(2000)=" << leapyear(2000) << '\n';
  cout << "leapyear(1900)=" << leapyear(1900) << '\n';

}
