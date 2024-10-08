#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(const string& s, const string& w) {
  vector<string> strings;
  istringstream iss{s};

  string temp{};
  for (const char c : s) {
    if (isspace(c) || w.contains(c)) {
      if (!temp.empty()) {
        strings.push_back(temp);
        temp = "";
      }
      continue;
    }
    temp += c;
  }
  if (!temp.empty()) strings.push_back(temp);
  return strings;
}

int main() {
  for (const auto& s : split("this is a test", "i")) {
    cout << s << '\n';
  }
}
