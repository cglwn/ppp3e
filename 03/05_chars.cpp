#include <iostream>

using namespace std;

int main() {
  int i = 'a';
  while (i <= 'z') {
    cout << static_cast<char>(i) << '\t' << i << '\n';
    ++i;
  }
}