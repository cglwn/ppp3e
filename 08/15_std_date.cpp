#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
  auto birthday = April/21/1994;
  cout << static_cast<int>(birthday.year()) << '\n';
}
