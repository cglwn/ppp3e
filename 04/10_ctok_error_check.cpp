#include <iostream>
#include <stdexcept>

using namespace std;

double ctok(double c) {
  double k = c + 273.15;
  return k;
}

int main() {
  double c = 0;
  cin >> c;
  if (c < -273.15) {
    throw runtime_error("temperature must be above -273.15C");
  }
  double k = ctok(c);
  cout << k << '\n';
}
