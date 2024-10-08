#include <stdexcept>

#include "token.h"
Token get_token() { throw std::runtime_error("not implemented"); }

double term() { throw std::runtime_error("not implemented"); }

double expression() {
  double left = term();
  Token t = get_token();
  while (t.kind=='+' || t.kind=='-') {
    if (t.kind == '+')
      left += term();
    else
      left -= term();
    t = get_token();
  }
  return left; // no more + or -, return the answer
}

int main() {}