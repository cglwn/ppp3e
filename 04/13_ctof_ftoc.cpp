#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

double ctof(double c) {
  if (c < -273.15) {
    throw runtime_error("temperature must be above -273.15C");
  }
  const double f = (9.0 / 5.0) * c + 32.0;
  return f;
}

double ftoc(double f) {
  if (f < -459.67) {
    throw runtime_error("temperature must be above -459.67F");
  }
  const double c = (f - 32.0) * (5.0 / 9.0);
  return c;
}

int main() {
  cout << "Enter a temperature in (c)elsius or (f)ahrenheit: \n";

  // Read a number and a unit. Due to a libc++ bug, we need a space before the
  // unit if reading directly from cin see
  // https://bugs.llvm.org/show_bug.cgi?id=17782
  string input;
  cin >> input;

  int offset = 0;
  if (find(input.begin(), input.end(), ' ') != input.end()) {
    offset = 1;
  }
  double val = stod(input.substr(0, input.size() - offset));
  char unit = static_cast<char>(tolower(input[input.size() - 1]));

  switch(unit) {
    case 'c':
      cout << ctof(val) << "F\n";
      break;
    case 'f':
      cout << ftoc(val) << "C\n";
      break;
    default:
      throw runtime_error("unknown unit");
  }
}
