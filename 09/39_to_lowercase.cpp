#include <fstream>
#include <iostream>

using namespace std;

void tolower(string& s) {
  for (char& c : s) {
    c = tolower(c);
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    cerr << "Incorrect number of arguments\n";
    cerr << "Usage: " << argv[0] << " input_file output_file";
  }

  ifstream ifs{argv[1]};
  ofstream ofs{argv[2]};
  string s;
  while (getline(ifs, s)) {
    tolower(s);
    ofs << s << '\n';
  }
}
