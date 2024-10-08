#include <fstream>
#include <iostream>

using namespace std;

bool is_vowel(char c) {
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Incorrect number of arguments.\n";
    cerr << "Usage: " << argv[0] << " file";
  }

  ifstream ifs{argv[1]};
  string s;
  while (getline(ifs, s)) {
    for (char& c : s) {
      if (!is_vowel(c)) {
        cout << c;
      }
    }
    cout << '\n';
  }
}
