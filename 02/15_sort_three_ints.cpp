#include <algorithm>
#include <array>
#include <iostream>

using namespace std;
int main() {
  array<int, 3> vals{};
  for (int i = 0; i < 3; ++i) {
    cin >> vals[i];
  }
  ranges::sort(vals);
  cout << vals[0] << ", " << vals[1] << ", " << vals[2] << '\n';
}
