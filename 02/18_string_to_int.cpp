#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  const map<string, int> m{
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
  };
  cout << "Enter a spelled-out number from zero to four:\n";
  string s;
  cin >> s;
  if (m.find(s) == m.end()) {
    cout << "stupid computer!";
  } else {
    cout << m.at(s);
  }
}
