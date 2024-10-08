#include <iostream>
#include <limits>

using namespace std;

int main() {
  int squares = 1;
  int rice_i = 1;

  while (rice_i * 2 > rice_i) {
    squares += 1;
    rice_i *= 2;
  }
  cout << squares << " squares before overflowing\n";

  squares = 1;
  double rice_d = 1;
  while (rice_d * 2 < numeric_limits<double>::max()) {
    squares += 1;
    rice_d *= 2;
  }
  cout << squares << " squares before hitting maximum double\n";
}
