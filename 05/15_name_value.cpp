#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class NameValue {
public:
  string name;
  int value;
};

int main() {
  cout << "Enter name and value pairs:\n";

  string line;

  vector<NameValue> scores;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    istringstream iss{line};
    NameValue nv;
    iss >> nv.name >> nv.value;
    scores.push_back(std::move(nv));
  }

  cout << "Enter a value to search for:\n";
  while (getline(cin, line)) {
    bool found = false;
    for (const auto nv : scores) {
      int i;
      istringstream iss{line};
      iss >> i;
      if (nv.value == i) {
        found = true;
        cout << nv.name << '\n';
      }
    }
    if (!found) {
      cout << "score not found\n";
    }
  }
}
