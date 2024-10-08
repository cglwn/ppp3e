#include <format>
#include <iostream>
#include <version>

using namespace std;

int main() {
#ifdef __cpp_lib_format
  cout << "Enter your name:\n";
  string val;
  cin >> val;
  string s = format("Hello, {}!\n", val);
  cout << s << '\n';
#else
  cerr << "Compiler of this binary did not support std::format so this example cannot be run.\n"
       << "Please recompile with a compiler that supports std::format.\n";
  return 1;
#endif
}
