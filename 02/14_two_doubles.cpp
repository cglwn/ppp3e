#include <iostream>

using namespace std;

int main() {
  double d1;
  double d2;
  cout << "Enter two doubles:\n";
  cin >> d1;
  cin >> d2;
  cout << "min(" << d1 << ", " << d2 << ") == " << min(d1, d2) << '\n';
  cout << "max(" << d1 << ", " << d2 << ") == " << max(d1, d2) << '\n';
  cout << d1 << " + " << d2 << " == " << d1 + d2 << '\n';
  cout << d1 << " - " << d2 << " == " << d1 - d2 << '\n';
  cout << d1 << " * " << d2 << " == " << d1 * d2 << '\n';
  cout << d1 << " / " << d2 << " == " << d1 / d2 << '\n';
}
