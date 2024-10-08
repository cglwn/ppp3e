#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  double d1;
  cout << "Enter a number: \n";
  cin >> d1;
  double d2;
  cout << "Enter another number: \n";
  cin >> d2;
  char operation;
  cout << "Enter an operation (+, -, /, *): \n";
  cin >> operation;
  switch(operation) {
    case '+':
      cout << "The sum of " << d1 << " and " << d2 << " is " << d1 + d2 << ".\n";
      break;
    case '-':
      cout << "The difference of " << d1 << " and " << d2 << " is " << d1 - d2 << ".\n";
      break;
    case '*':
      cout << "The product of " << d1 << " and " << d2 << " is " << d1 * d2 << ".\n";
      break;
    case '/':
      cout << "The quotient of " << d1 << " and " << d2 << " is " << d1 / d2 << ".\n";
    default:
      throw runtime_error("unknown operation");
  }
}
