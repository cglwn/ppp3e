#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Incorrect number of arguments.\n";
    cerr << "Usage: " << argv[0] << " <file>";
    return 1;
  }

  ifstream ifs{argv[1]};
  if (!ifs) {
    cerr << "Could not open file\n";
    return 1;
  }

  string s;
  stack<string> words;
  while (ifs >> s) {
    words.push(s);
  }
  while (!words.empty()) {
    cout << words.top() << " ";
    words.pop();
  }
}
