#include <iostream>

using namespace std;

double ctok(double c) {
  /* int k = c + 273.25; <- k should not be an int and it should be 273.15*/
  double k = c + 273.15;
  /* return int; <- should not be return int and instead return k */
  return k;
}

int main() {
  double c = 0;
  /* cin >> d; <- cin should be read into c */
  cin >> c;
  /* double k = ctok("c"); <- ctok argument should be c */
  double k = ctok(c);
  /* Cout << k <<'\n'; <- cout should not be capitalized */
  cout << k << '\n';
}
