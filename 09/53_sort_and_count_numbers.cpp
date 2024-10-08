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

  int i;
  map<int, int> counts;
  while (ifs >> i) {
    ++counts[i];
  }
  for (const auto& [k, v] : counts) {
    cout << k;
    if (v != 1) {
      cout << '\t' << v;
    }
    cout << '\n';
  }
}
