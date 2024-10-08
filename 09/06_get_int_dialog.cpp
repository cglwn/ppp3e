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
int get_int(int low, int high, const string& greeting, const string& sorry) {
  cout << greeting << ": [" << low << ":" << high << "]\n";
  while (true) {
    int n = get_int();
    if (low <= n && n <= high)
      return n;
    cout << sorry << ": [" << low << ':' << high << "]\n";
  }
}

int main() {
  int strength = get_int(1, 10, "enter strength", "Not in range, try again");
  cout << "strength: " << strength << '\n';

  int altitude = get_int(0, 50'000, "Please enter altitude in feet", "Not in range, please try again");
  cout << "altitude: " << altitude << "f above sea level\n";
}
