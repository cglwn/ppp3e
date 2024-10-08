#include <iostream>

using namespace std;

// Which output form presents the user with the most accurate
// representation? Explain why.
//
// Background
//
// ## Floating-point formats
// fixed: use fixed-point notation
// scientific: use mantissa and exponent notation
//             the mantissa is always in the [1:10) range
//             that is, there is a single nonzero digit before the
//             decimal point
// defaultfloat: choose fixed or scientific to give the numerically most
//               accurate definition
// hexfloat: use scientific notation with hexadecimal for mantissa and
//           exponent
//
// ## Floating-point precision
// defaultfloat: precision is the total number of digits
// scientific: precision is the number of digits after the decimal point
// fixed: precision is the number of digits after the decimal point
//
// Answer
// fixed presents the most accurate representation showing all the
// significant digits. This is because defaultfloat has a default
// precision of six digits while the number 1234567.89 has 9 significant
// digits.
int main() {
  double d = 1234567.89;
  cout << defaultfloat << d << " - "
       << fixed << d << " - "
       << scientific << d << '\n';
}
