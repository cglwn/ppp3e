#include <stdexcept>

#include "token.h"
Token get_token() { throw std::runtime_error("not implemented"); }

double term() { throw std::runtime_error("not implemented"); }

double expression() {
  double left = term();
  Token t = get_token();
  switch (t.kind) {
    case '+':
      return left + expression();
    case '-':
      return left - expression();
    default:
      return left;
  }
}

int main() {}