#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  string day;
  int val{};

  map<string, set<string>> day_names;
  day_names["Monday"]= set<string>{"Monday", "Mon", "monday"};
  day_names["Tuesday"] = set<string>{"Tuesday", "Tue", "tuesday"};
  day_names["Wednesday"] = set<string>{"Wednesday", "Wed", "wednesday"};
  day_names["Thursday"] = set<string>{"Thursday", "Thu", "thursday"};
  day_names["Friday"] = set<string>{"Friday", "Fri", "friday"};
  day_names["Saturday"] = set<string>{"Saturday", "Sat", "saturday"};
  day_names["Sunday"] = set<string>{"Sunday", "Sun", "sunday"};

  map<string, vector<int>> day_values;

  int num_rejected = 0;
  cout << "Enter a day and a value\n";
  while (cin >> day >> val) {
    bool found = false;
    for (const auto& [k, v] : day_names) {
      if (v.contains(day)) {
        found = true;
        day_values[k].push_back(val);
      }
    }
    if (!found) {
      cerr << "Day name " << day << " not recognized\n";
    }
  }
  for (const auto& [k, v] : day_values) {
    const int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum for " << k << " is " << sum << '\n';
  }
  cout << num_rejected << " values rejected\n";
}
