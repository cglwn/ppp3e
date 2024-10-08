#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  cout << "Enter a, b, and c for a quadratic ax^2 + bx + c:\n";
  double a;
  double b;
  double c;
  cin >> a >> b >> c;

  const double d = pow(b, 2) - 4*a*c;
  if (d < 0) {
    cerr << "determinant " << d << " is negative";
    return 1;
  }
  const double sqrt_d = sqrt(d);
  const double x1 = (-b + sqrt_d) / (2*a);
  const double x2 = (-b + sqrt_d) / (2*a);
  cout << "x1=" << x1 << ", x2=" << x2 << '\n';
}
