#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int len = 4;
int main() {
  const vector<int> hidden{1, 2, 3, 4};
  const unordered_set<int> uniq{hidden.begin(), hidden.end()};

  string input;
  while (cin >> input) {
    if (input.size() != 4) {
      cerr << "Enter 4 digits (ex: 1122)\n";
      continue;
    }
    unordered_set<int> seen;
    int bulls = 0;
    int cows = 0;
    vector<int> ans(4);

    for (int i = 0; i < len; ++i) {
      ans[i] = input[i] - '0';
      if (ans[i] < 0 || ans[i] > 9) {
        cerr << "Digit " << i << " = " << input[i] << " was not a number\n";
        return 1;
      }
    }

    for (int i = 0; i < len; ++i) {
      // Each bull is a digit in the right position
      // Each cow is a correct digit in the wrong position

      if (ans[i] == hidden[i] &&
          !seen.contains(ans[i])) {
        bulls++;
      } else if (
        find(
          hidden.begin(),
          hidden.end(),
          ans[i]) != hidden.end() &&
        !seen.contains(ans[i])) {
        cows++;
      }
      seen.emplace(ans[i]);
    }
    if (bulls == len) {
      cout << "4 bulls. You win\n";
      return 0;
    }

    string bull_word = bulls == 1 ? "bull" : "bulls";
    string cow_word = cows == 1 ? "cow" : "cows";
    cout << bulls << " " << bull_word << " and " << cows << " " << cow_word << "\n";
  }
}
