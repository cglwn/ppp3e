#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(const string& s) {
  vector<string> strings;
  istringstream iss{s};

  string temp;
  while (iss >> temp) {
    strings.push_back(temp);
  }
  return strings;
}

int main() {
  for (const auto& s : split("this is a test")) {
    cout << s << '\n';
  }
}
