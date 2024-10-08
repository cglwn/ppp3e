#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  if (argc != 3) {
    cerr << "Incorrect number of arguments\n";
    cerr << "Usage: " << argv[0] << " input_file word";
  }

  ifstream ifs{argv[1]};
  string s;

  int line = 0;
  while (getline(ifs, s)) {
    ++line;
    if (s.contains(argv[2])) {
      cout << "[Line " << line << "]: " << s << '\n';
    }
  }
}
