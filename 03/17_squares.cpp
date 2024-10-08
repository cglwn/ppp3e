#include <iostream>

using namespace std;

int main() {
  int squares = 1;
  int rice = 1;

  for (const auto x : {1'000, 1'000'000, 1'000'000'000}) {
    while (rice < x) {
      rice *= 2;
      squares += 1;
    }
    cout << squares << " squares  for " << x << " grains of rice.\n";
  }
}
