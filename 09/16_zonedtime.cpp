#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;
using namespace chrono_literals;


int main() {
  // Not currently supported in Clang 15.0.0
#if false
  cout << "birthday: " << April/21/1994 << '\n';
  cout << "zt:  << " << zoned_time{current_zone(), system_clock::now()} << '\n';
#endif
}
