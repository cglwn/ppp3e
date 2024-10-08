#include <format>
#include <iostream>
#include <version>

using namespace std;

int main() {
#ifdef __cpp_lib_format
  constexpr double d = 1234.56789;
  cout << format("{} - {:a} - {:e} - {:f} - {:g}\n", d, d, d, d, d);
#else
  cerr << "Compiler of this binary did not support std::format so this example cannot be run.\n"
       << "Please recompile with a compiler that supports std::format.\n";
  return 1;
#endif
}
