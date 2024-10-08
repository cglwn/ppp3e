#include <iostream>

using namespace std;

int main() {
  int a;
  int b;
  int c;
  int d;
  cin >> a >> oct >> b >> hex >> c >> d;
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
  // Prints out 1234 668 4660
  // We read in as decimal, octal, then hexadecimal.
  // a is printed out as 1234 as read in.
  //
  // b is printed out as decimal but was read in as octal.
  // 1234₈ = 1000₈ + 200₈ + 30₈ + 4₈
  //       = 1×8³  + 2×8² + 3×8 + 4×8⁰
  //       = 512 + 128 + 24 + 4
  //       = 668
  //
  // c is printed out as decimal but was read in as hexadecimal.
  // 1234₁₆ = 1000₁₆ + 200₁₆ + 30₁₆ + 4₁₆
  //        = 1×16³  + 2×16² + 3×16 + 4×16⁰
  //        = 4096 + 512 + 48 + 4
  //        = 4660
}
