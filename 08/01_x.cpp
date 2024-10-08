#include <iostream>

using namespace std;

class X {
public:
  // data member
  int m;

  // function member
  int mf(int v) {
    int old = m;
    m = v;
    return old;
  }
};

int main() {
  X var;
  var.m = 7;
  cout << "var.m=" << var.m << '\n';
  cout << "var.mf(9)=" << var.mf(9) << '\n';
  cout << "var.m=" << var.m << '\n';
}
