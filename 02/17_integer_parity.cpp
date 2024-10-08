#include <iostream>

using namespace std;

int main() {
  cout << "Enter an integer:\n";
  int i;
  cin >> i;
  switch (i % 2) {
    case 0:
      cout << i << " is even";
      break;
    case 1:
      cout << i << " is odd";
      break;
  }
}
