#include <iostream>

using namespace std;

int square(int x) {
  int x_squared = 0;
  for (int i = 0; i < x; ++i) {
    x_squared += x;
  }
  return x_squared;
}

int main() {
  int i = 0;
  while (i < 100) {
    cout << i << '\t' << square(i) << '\n';
    ++i;
  }
}