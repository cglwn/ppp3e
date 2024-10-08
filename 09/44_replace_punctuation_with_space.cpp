#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const vector<char> replaceables{'.', ';', ',', '?', '-', '\''};
  string s;

  while (getline(cin, s)) {
    const long int num_quotes = ranges::count(s, '"');
    const bool even_num_quotes = (num_quotes % 2) == 0;
    int quotes_seen = 0;
    bool inside_quote = false;
    for (const char c : s) {
      const bool replace =
        ranges::find(replaceables, c) != replaceables.end();
      if (c == '"') {
        inside_quote = !inside_quote;
        ++quotes_seen;
        cout << c;
      } else if (!inside_quote && even_num_quotes && replace) {
        cout << ' ';
      }
      else {
        cout << c;
      }
    }

    cout << '\n';
  }
}
