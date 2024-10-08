// exercise 3.[7]
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  const vector<string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  cout << "Enter a number: \n";

  string number;

  while (cin >> number) {
    if (number.size() == 1 && isdigit(number[0])) {
      istringstream iss{number};
      int n;
      iss >> n;
      cout << numbers[n] << '\n';
    } else {
      auto idx = find(numbers.begin(), numbers.end(), number);
      if (idx == numbers.end()) {
        cout << "Unknown input " << number << '\n';
      } else {
        cout << idx - numbers.begin() << '\n';
      }
    }
    cout << "\nEnter a number: \n";
  }
}
