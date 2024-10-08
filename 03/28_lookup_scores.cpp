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

  int query_score;
  while (true) {
    cout << "Enter a score to lookup:\n";
    if (!(cin >> query_score))
      break;

    auto score_iter = find(scores.begin(), scores.end(), query_score);
    if (score_iter == scores.end()) {
      cout << "score not found\n\n";
      continue;
    }
    for (int i = 0; i < names.size(); ++i) {
      if (scores[i] == query_score) {
        cout << names[i] << '\n';
      }
    }
    cout << '\n';
  }
}
