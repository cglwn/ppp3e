#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;
int main() {
  array<string, 3> vals{};
  for (int i = 0; i < 3; ++i) {
    cin >> vals[i];
  }
  ranges::sort(vals);
#if FALSE
  For input `a b c` this prints a11296b11296c
  cout << vals[0] << ', ' << vals[1] << ', ' << vals[2] << '\n';
#endif
  cout << vals[0] << ", " << vals[1] << ", " << vals[2] << '\n';
}
