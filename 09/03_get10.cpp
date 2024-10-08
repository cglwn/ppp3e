#include <iostream>

using namespace std;

int get10() {
  cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
  int n = 0;
  while (true) {
    cin >> n;
    if (cin) {
      if (1 <= n && n <= 10)
        return n;
      cout << "Sorry " << n << " is not in the [1:10] range; please try again\n";
    } else if (cin.fail()) {
      cin.clear();
      cout << "Sorry that was not a number; please try again\n";
      for (char ch; cin >> ch && !isdigit(ch););
      if (!cin)
        throw runtime_error("no input");
      cin.unget();
    } else
      throw runtime_error("no input");
  }
}

int main() {
  get10();
}
