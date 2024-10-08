// Convert Celsius to/from Fahrenheit
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

double ctok(double c) {
  if (c < -273.15) {
    throw runtime_error("temperature must be above -273.15C");
  }
  double k = c + 273.15;
  return k;
}

double ktoc(double k) {
  if (k < 0) {
    throw runtime_error("temperature must be above 0K");
  }
  double c = k - 273.15;
  return c;
}

int main() {
  cout << "Enter a temperature in (c)elsius or (k)elvin: \n";

  // Read a number and a unit. Due to a libc++ bug, we need a space before the
  // unit see https://bugs.llvm.org/show_bug.cgi?id=17782
  string input;
  cin >> input;

  int offset = 0;
  if (find(input.begin(), input.end(), ' ') != input.end()) {
    offset = 1;
  }
  double val = stod(input.substr(0, input.size() - offset));
  char unit = input[input.size() - 1];

  cout << "unit=" << unit;
  switch(unit) {
    case 'c':
      cout << ctok(val) << "K\n";
      break;
    case 'k':
      cout << ktoc(val) << "C\n";
      break;
    default:
      throw runtime_error("unknown unit");
  }
}
