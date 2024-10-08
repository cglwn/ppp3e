#include <iostream>

using namespace std;

constexpr double cm_per_in = 2.51;

int main() {
  int val;
  char unit;
  cout << "Enter a unit to convert:\n";
  cin >> val >> unit;
  switch(unit) {
    case 'c':
      cout << val / cm_per_in << " in \n";
      break;
    case 'i':
      cout << val * cm_per_in << " cm \n";
      break;
    default:
      cerr << "Unknown unit " << unit << '\n';
      return 1;
  }
}
