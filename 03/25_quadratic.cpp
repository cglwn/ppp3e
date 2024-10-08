#include <iostream>

using namespace std;

int main() {
  cout << "Enter a, b, c of a quadratic: \n";
  double a;
  double b;
  double c;
  cin >> a >> b >> c;
  double d = sqrt(b*b - 4*a*c);
  double x1 = (-b + d)/(2*a);
  double x2 = (-b - d)/(2*a);
  cout << "x1 is " << x1 << ", x2 is " << x2 << '\n';
}
