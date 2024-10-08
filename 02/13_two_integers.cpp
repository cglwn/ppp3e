#include <iostream>

using namespace std;

int main() {
  int i1;
  int i2;
  cout << "Enter two integers:\n";
  cin >> i1;
  cin >> i2;
  cout << "min(" << i1 << ", " << i2 << ") == " << min(i1, i2) << '\n';
  cout << "max(" << i1 << ", " << i2 << ") == " << max(i1, i2) << '\n';
  cout << i1 << " + " << i2 << " == " << i1 + i2 << '\n';
  cout << i1 << " - " << i2 << " == " << i1 - i2 << '\n';
  cout << i1 << " * " << i2 << " == " << i1 * i2 << '\n';
  cout << i1 << " / " << i2 << " == " << i1 / i2 << '\n';
}
