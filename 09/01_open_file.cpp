#include <fstream>
#include <iostream>

using namespace std;

int main() {
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist {iname};
  if (!ist)
    throw runtime_error("can't open input file " + iname);
}
