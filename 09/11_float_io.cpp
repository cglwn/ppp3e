#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  constexpr double d = 1234.56789;

  cout << "format: " << d << " - "
       << hexfloat << d << " - "
       << scientific << d << " - "
       << fixed << d << " - "
       << defaultfloat << d << '\n';

  cout << "width: " << d << " - " << setw(8) << d << " - " << setw(16) << d << '\n';
}
