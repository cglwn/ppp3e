#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Incorrect number of arguments.\n";
    cerr << "Usage: " << argv[0] << " <file>";
    return 1;
  }
  ifstream ifs{argv[1]};
  if (!ifs) {
    cerr << "Could not open " << argv[1] << '\n';
    return 1;
  }

  string s;
  map<string, int> counts;
  while (getline(ifs, s)) {
    for (const char& c : s) {
      if (isspace(c)) { ++counts["space"]; }
      if (isalpha(c)) { ++counts["alpha"]; }
      if (isdigit(c)) { ++counts["digit"]; }
      if (isxdigit(c)) { ++counts["xdigit"]; }
      if (isupper(c)) { ++counts["upper"]; }
      if (islower(c)) { ++counts["lower"]; }
      if (isalnum(c)) { ++counts["alnum"]; }
      if (iscntrl(c)) { ++counts["cntrl"]; }
      if (ispunct(c)) { ++counts["punct"]; }
      if (isprint(c)) { ++counts["print"]; }
      if (isgraph(c)) { ++counts["graph"];}
    }
  }

  for (const auto& [k, v] : counts) {
    cout << k << ": " << v << '\n';
  }
}
