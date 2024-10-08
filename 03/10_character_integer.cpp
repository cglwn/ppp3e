#include <iostream>

using namespace std;

int main() {
  cout << "Enter a string:\n";
  char c;
  while (cin >> c) {
    cout << c << " " << static_cast<int>(c) << '\n';
  }
}