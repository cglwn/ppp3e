#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int get_digit() {
  const vector<string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  cout << "Enter a number: \n";

  string number;
  cin >> number;
  if (number.size() == 1 && isdigit(number[0])) {
    istringstream iss{number};
    int n;
    iss >> n;
    return n;
  }
  auto idx = find(numbers.begin(), numbers.end(), number);
  if (idx == numbers.end()) {
    throw std::runtime_error("unknown number");
  } else {
    return static_cast<int>(idx - numbers.begin());
  }
}

int main() {
  int i1 = get_digit();
  int i2 = get_digit();
  char operation;
  cout << "Enter an operation (+, -, /, *): \n";
  cin >> operation;
  switch(operation) {
    case '+':
      cout << "The sum of " << i1 << " and " << i2 << " is " << i1 + i2 << ".\n";
      break;
    case '-':
      cout << "The difference of " << i1 << " and " << i2 << " is " << i1 - i2 << ".\n";
      break;
    case '*':
      cout << "The product of " << i1 << " and " << i2 << " is " << i1 * i2 << ".\n";
      break;
    case '/':
      cout << "The quotient of " << i1 << " and " << i2 << " is " << i1 / i2 << ".\n";
    default:
      throw runtime_error("unknown operation");
  }
}
