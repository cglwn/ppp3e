#include <fstream>
#include <iostream>

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

  int sum = 0;
  int i;
  while (ifs >> i) {
    sum += i;
  }
  cout << "Sum is " << sum << '\n';
}
