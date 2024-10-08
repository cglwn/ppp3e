#include <format>
#include <iostream>
#include <version>

using namespace std;

int main() {
#ifdef __cpp_lib_format
  int x = 1234;
  cout << format("{} - {:x} - {:o} - {:d} - {:b}\n", x, x, x, x, x);
#else
  cerr << "Compiler of this binary did not support std::format so this example cannot be run.\n"
       << "Please recompile with a compiler that supports std::format.\n";
  return 1;
#endif
}
