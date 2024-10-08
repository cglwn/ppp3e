#include <iostream>

using namespace std;

int main() {
  for (int i = 'a'; i <= 'z'; ++i) {
    cout << static_cast<char>(i) << '\t' << i << '\n';
  }
}