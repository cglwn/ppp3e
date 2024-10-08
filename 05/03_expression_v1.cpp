// Implements the rules of the grammar
// Expression:
//   Term
//   Expression "+" Term
//   Expression "-" Term
// Term:
//   Primary
//   Term "*" Primary
//   Term "/" Primary
//   Term "%" Primary
// Primary:
//   Number
//   "(" Expression ")"
// Number:
//   floating-point-literal

#include <stdexcept>

#include "token.h"
Token get_token() { throw std::runtime_error("not implemented"); }

double term() { throw std::runtime_error("not implemented"); }

double expression() {
  double left = expression();
  Token t = get_token();
  switch (t.kind) {
    case '+':
      return left + term();
    case '-':
      return left - term();
    default:
      return left;
  }
}

int main() {}