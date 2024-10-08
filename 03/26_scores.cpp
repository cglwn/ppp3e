#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> names;
  vector<int> scores;

  cout << "Enter name-and-value pairs:\n";
  string name;
  int score;
  while (cin >> name >> score) {
    if (find(names.begin(), names.end(), name) != names.end()) {
      throw runtime_error("duplicate name");
    }
    names.emplace_back(name);
    scores.emplace_back(score);
  }

  for (int i = 0; i < names.size(); ++i) {
    cout << names[i] << " " << scores[i] << '\n';
  }
}
