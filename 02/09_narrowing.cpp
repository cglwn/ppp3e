#include <iostream>

using namespace std;

int main() {
  cout << "Enter a floating-point value: \n";
  double d = 0;
  while (cin >> d) {
    int i = d;
    char c = i;
    cout << "d==" << d
         << " i==" << i
         << " c==" << c
         << " char(" << c << ")\n";
  }
}
