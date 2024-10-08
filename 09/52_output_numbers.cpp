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

  double d;
  while (ifs >> d) {
    cout << setw(20) << d << " - "
         << scientific << d << " - "
         << setprecision (8) << d << '\n';
  }
  // outputs a file of numbers using scientific format and precision 8
  // four fields of 20 characters per line

}
