#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> names;
  vector<int> scores;

  cout << "Enter name-and-value pairs (enter a blank line to start querying):\n";
  string name;
  int score;
  string line;
  while (getline(cin, line)) {
    if (line.empty())
      break;
    istringstream iss{line};
    iss >> name >> score;
    if (find(names.begin(), names.end(), name) != names.end()) {
      throw runtime_error("duplicate name");
    }
    names.emplace_back(name);
    scores.emplace_back(score);
  }

  string query_name;
  while (true) {
    cout << "Enter a name to lookup:\n";
    if (!(cin >> query_name))
      break;

    auto names_iter = find(names.begin(), names.end(), query_name);
    if (names_iter == names.end()) {
      cout << "name not found\n\n";
      continue;
    }
    cout << scores[names_iter - names.begin()] << "\n\n";
  }
}
