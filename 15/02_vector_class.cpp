#include <iostream>

using namespace std;

class Vector {
public:
  int size;
  double age0, age1, age2, age3;
};
int main() {
  Vector vec;
  vec.age0 = 0.33;
  vec.age1 = 22.0;
  vec.age2 = 27.2;
  vec.age3 = 54.2;
  // no way to vec.push_back
}
