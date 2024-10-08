#include <iostream>
#include <stdexcept>

using namespace std;

class Token {
public:
  char kind;
  double value;
  Token() : kind(' '), value{0.0} {}
  explicit Token(char k) : kind{k}, value{0.0} {}
  Token(char k, double v) : kind{k}, value{v} {}
};

class Token_stream {
public:
  Token get(); // get a Token
  void putback(Token t); // put a Token back
private:
  bool full = false; // is there a Token in the buffer?
  Token buffer; // putback() saves its token here
};

void Token_stream::putback(Token t) {
  if (full)
    throw runtime_error("putback() into a full buffer");
  buffer = t;
  full = true;
}
Token Token_stream::get() {
  if (full) {
    full = false;
    return buffer;
  }
  char ch = 0;
  if (!(cin >> ch))
    throw runtime_error("no input");

  switch (ch) {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
      return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
      cin.putback(ch);
      double val = 0;
      cin >> val;
      return Token{'8', val};
    }
    default:
      throw runtime_error("Bad token");
  }
}

Token_stream ts;
double expression();

double primary() {
  Token t = ts.get();
  switch (t.kind) {
    case '(': {
      double d = expression();
      t = ts.get();
      if (t.kind != ')')
        throw runtime_error("')' expected");
      return d;
    }
    case '8':
      return t.value;
    default:
      throw runtime_error("primary expected");
  }
}
double term() {
  double left = primary();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary();
        t = ts.get();
        break;
      case '/':
      {
        double d = primary();
        if (d == 0)
          throw runtime_error("divide by zero");
        left /= d;
        t = ts.get();
        break;
      }
      default:
        ts.putback(t);
        return left;
    }
  }
}
double expression() {
  double left = term();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
      case '+':
        left += term();
        t = ts.get();
        break;
      case '-':
        left -= term();
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left;
    }
  }
}

int main() {
  try {
    while (cin) {
      cout << "> ";
      Token t = ts.get();
      while (t.kind == ';')
        t = ts.get(); // eat ';'
      if (t.kind == 'q')
        return 0;
      ts.putback(t);
      cout << "= " << expression() << '\n';
    }
  } catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "exception \n";
    return 2;
  }
}
