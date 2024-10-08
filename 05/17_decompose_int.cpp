#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string print(char digit, const string& plural, const string& singular){
  ostringstream oss;
  oss << digit << ' ';
  if (digit == '1') {
    oss << singular;
  } else {
    oss << plural;
  }
  return oss.str();
}

int main() {
  cout << "Enter a number up to 4 digits long:\n";
  string s;
  cin >> s;
  if (s.size() > 4) {
    cerr << "Too many digits\n";
    return 1;
  }
  string words;
  for (int i = 0; i < s.size(); ++i) {
    auto pos = s.size() - i - 1;

    if (pos == 0) {
      words += print(s.at(i), "ones", "one");
    } else if (pos == 1) {
      words += print(s.at(i), "tens", "ten");
      words += " and ";
    } else if (pos == 2) {
      words += print(s.at(i), "hundreds", "hundred");
      words += " and ";
    } else if (pos == 3) {
      words += print(s.at(i), "thousands", "thousand");
      words += " and ";
    }
  }
  cout << words << '\n';
}
