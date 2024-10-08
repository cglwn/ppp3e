/* Simple calculator
 *
 * This program implements a basic expression calculator.
 * Input from cin; output to cout.
 * The grammar for input is:
 *
 * Statement:
 *   Expression
 *   Print
 *   Quit
 * Print:
 *   ";"
 * Quit:
 *   "q"
 * Expression:
 *   Term
 *   Expression "+" Term
 *   Expression "-" Term
 * Term:
 *   Primary
 *   Term "*" Primary
 *   Term "/" Primary
 *   Term "%" Primary
 * Primary:
 *   Number
 *   "(" Expression ")"
 *   "-" Primary
 *   "+" Primary
 * Number:
 *   floating-point-literal
 *
 * Input comes from cin through the Token_stream called ts.
 */
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

constexpr char number = '8';
constexpr auto prompt = "> ";
constexpr auto result = "= ";
constexpr char quit = 'q';
constexpr char print = ';';

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
  void ignore (char c); // discard characters up to and including a c
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
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
      cin.putback(ch);
      double val = 0;
      cin >> val;
      return Token{number, val};
    }
    default:
      throw runtime_error("Bad token");
  }
}

void Token_stream::ignore(char c) {
  if (full && c==buffer.kind) { // first look in buffer
    full = false;
    return;
  }
  full = false;

  // now search input:
  char ch = 0;
  while (cin >> ch)
    if (ch==c)
      return;
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
    case number:
      return t.value;
    case '-':
      return - primary();
    case '+':
      return primary();
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
      case '%':
      {
        int i1 = static_cast<int>(left);
        int i2 = static_cast<int>(primary());
        if (i2 == 0)
          throw runtime_error("%:divide by zero");
        left = i1%i2;
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

void clean_up_mess() {
  ts.ignore(print);
}

void calculate() {
  while (cin) try {
    cout << prompt;
    Token t = ts.get();
    while (t.kind == print)
      t = ts.get(); // eat ';'
    if (t.kind == quit)
      return;
    ts.putback(t);
    cout << result << expression() << '\n';
  } catch (exception& e) {
    cerr << e.what() << '\n';
    clean_up_mess();
  }
}

int main() {
  try {
    calculate();
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "exception \n";
    return 2;
  }
}
