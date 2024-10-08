#include <iostream>

using namespace std;

constexpr double dollars_per_yen = 100.0;
constexpr double dollars_per_kroner = 1.0;
constexpr double dollars_per_franc = 8.0;
constexpr double dollars_per_pound = 0.8;

int main() {
  int val;
  char unit;
  cout << "Enter an amount to convert in (y)en, (k)roner, (f)rancs or (p)ounds:\n";
  cin >> val >> unit;
  switch(unit) {
    case 'y':
      cout << '$' << val * dollars_per_yen << '\n';
      break;
    case 'k':
      cout << '$' << val * dollars_per_kroner << '\n';
      break;
    case 'f':
      cout << '$' << val * dollars_per_franc << '\n';
    case 'p':
      cout << '$' << val * dollars_per_pound << '\n';
      break;
    default:
      cerr << "Unknown unit " << unit << '\n';
      return 1;
  }
}
