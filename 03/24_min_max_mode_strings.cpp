#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << "Enter strings: \n";
  map<string, int> counts;
  vector<string> inputs;
  bool initialized = false;
  string min_s;
  string max_s;
  for (string s; cin >> s; counts[s]++) {
    if (!initialized) {
      min_s = s;
      max_s = s;
      initialized = true;
    }
    min_s = min(min_s, s);
    max_s = max(max_s, s);
  }
  cout << "The minimum string is " << min_s << '\n';
  cout << "The maximum string is " << max_s << '\n';

  string mode;
  int most_counts = 0;
  for (const auto& [val, count] : counts) {
    cout << "val=" << val << ", count=" << count << '\n';
    if (count > most_counts) {
      mode = val;
      most_counts = count;
    }
  }
  cout << "The mode is " << mode << '\n';
}
