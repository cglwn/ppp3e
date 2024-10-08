#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Incorrect number of arguments.\n";
    cerr << "Usage: " << argv[0] << " <file>";
    return 1;
  }

  stack<char> s;
  char c;
  ifstream ifs{argv[1]};
  while (ifs >> c) { s.push(c); }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}
