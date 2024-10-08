#include <stdexcept>

#include "token.h"
Token get_token() { throw std::runtime_error("not implemented"); }

double term() { throw std::runtime_error("not implemented"); }

double expression() {
  double left = term();
  Token t = get_token();
  while (true) {
    switch (t.kind) {
    case '+':
      left += term();
      t = get_token();
      break;
    case '-':
      left -= term();
      t = get_token();
      break;
    default:
      return left;
    }
  }
}

int main() {}