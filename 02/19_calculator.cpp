#include <iostream>
#include <string>

using namespace std;

int main() {
  string operation;
  cin >> operation;

  double op1;
  double op2;
  cin >> op1;
  cin >> op2;

  if (operation == "+" || operation == "plus") {
    cout << op1 + op2 << '\n';
  } else if (operation == "-" || operation == "minus") {
    cout << op1 - op2 << '\n';
  } else if (operation == "*" || operation == "mul") {
    cout << op1 * op2 << '\n';
  } else if (operation == "/" || operation == "div") {
    cout << op1 / op2 << '\n';
  } else {
    cerr << "Unknown operation " << operation << '\n';
  }
}
