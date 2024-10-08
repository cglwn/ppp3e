#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int64_t f0 = 1;
  int64_t f1 = 1;

  int n;
  cout << "How many Fibonacci numbers do you want?\n";
  cin >> n;

  int i = 0;
  while (i < n) {
    if (i == 0) {
      cout << f0;
      ++i;
      continue;
    } else if (i == 1) {
      cout << f1;
      ++i;
      continue;
    }
    int64_t tmp = f0 + f1;
    cout << tmp << '\n';
    f0 = f1;
    f1 = tmp;
    ++i;
  }

  while (f1 < numeric_limits<int>::max()) {
    int64_t tmp = f0 + f1;
    f0 = f1;
    f1 = tmp;
  }
  cout << "The largest Fibonacci number that fits into an int is " << f0 << '\n';
}
