#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int len = 4;
constexpr int az_min = 97;
constexpr int az_max = 122;

int main() {
  int n;
  cout << "Enter a random seed\n";
  cin >> n;
  default_random_engine engine(n);
  uniform_int_distribution<uint8_t> dist(az_min, az_max);

  vector<char> hidden(len);
  for (int i = 0; i < len; ++i) {
    uint8_t j = dist(engine);
    hidden[i] = static_cast<char>(j);
    cout << "hidden[i]=" << hidden[i] << '\n';
  }

  const unordered_set<int> uniq{hidden.begin(), hidden.end()};

  string input;
  cout << "Enter 4 digits (ex: 1122)\n";
  while (cin >> input) {
    if (input.size() != 4) {
      cerr << "Enter 4 digits (ex: 1122)\n";
      continue;
    }
    unordered_set<char> seen;
    int bulls = 0;
    int cows = 0;
    vector<char> ans(4);

    for (int i = 0; i < len; ++i) {
      ans[i] = input[i];
      if (ans[i] < az_min || ans[i] > az_max) {
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
        find(hidden.begin(), hidden.end(), ans[i]) != hidden.end() && !seen.contains(ans[i])) {
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
