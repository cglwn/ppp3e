#include <iostream>

using namespace std;

void skip_to_int() {
  if (cin.fail()) {
    cin.clear();
    for (char ch; cin >> ch;) {
      if (isdigit(ch) || ch == '-') {
        cin.unget();
        return;
      }
    }
  }
  throw runtime_error("no input");
}
int get_int() {
  int n = 0;
  while (true) {
    if (cin >> n)
        return n;
      cout << "Sorry, that was not a number; please try again\n";
      skip_to_int();
  }
}
int get_int(int low, int high) {
  cout << "Please enter an integer in the range "
       << low << " to " << high << "(inclusive):\n";
  while (true) {
    int n = get_int();
    if (low <= n && n <= high)
      return n;
    cout << "Sorry "
         << n << " is not in the [" << low << ':' << high
         << "] range; please try again\n";
  }
}

int main() {
  get_int(1, 10);
}
