#include <iostream>

#include "token.h"

using namespace std;

double primary() { throw runtime_error("not implemented"); }

Token get_token() { throw runtime_error("not implemented"); }
double term() {
  double left = primary();
  Token t = get_token();
  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary();
        t = get_token();
        break;
      case '/':
      {
        double d = primary();
        if (d == 0)
          throw runtime_error("divide by zero");
        left /= primary();
        t = get_token();
        break;
      }
#if FALSE // Won't compile because '%' not supported on doubles.
      case '%':
        left %= primary();
        t = get_token();
        break;
#endif
      default:
        return left;
    }
  }
}
int main() {
}
