#include <iostream>
#include <stdexcept>
#include <string>
#include <queue>
#include <vector>

using namespace std;

constexpr char number = '8';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr auto prompt = "> ";
constexpr auto result = "= ";
constexpr auto declkey = "let";
constexpr char quit = 'q';
constexpr char print = ';';

class Token {
public:
  char kind;
  double value;
  string name;
  Token() : kind(0) {}
  explicit Token(char k) : kind{k}, value{0.0} {}
  Token(char k, double v) : kind{k}, value{v} {}
  Token(char ch, string& n) : kind{ch}, name{n} {}
};

class Token_stream {
public:
  Token get(); // get a Token
  void putback(Token t); // put a Token back
  void ignore (char c); // discard characters up to and including a c
private:
  bool full = false; // is there a Token in the buffer?
  queue<Token> buffer; // putback() saves its token here
};

void Token_stream::putback(Token t) {
  buffer.push(t);
}
Token Token_stream::get() {
  if (!buffer.empty()) {
    Token token = buffer.front();
    buffer.pop();
    return token;
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
    case '=':
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
      if (isalpha(ch) || ch == '_') {
        string s;
        s += ch;
        const auto valid_in_identifier = [] (char c) {
          return (isalpha(c)||isdigit(c) || c == '_');
        };
        while (cin.get(ch) && valid_in_identifier(ch))
          s += ch;
        cin.putback(ch);
        if (s == declkey)
          return Token{let};
        return Token{name, s};
      }
      throw runtime_error("Bad token " + string{ch});
  }
}
void Token_stream::ignore(char c) {
  while (!buffer.empty()) { // first look in buffer
    char front = buffer.front().kind;
    buffer.pop();
    if (front == c) {
      return;
    }
  }

  // now search input:
  char ch = 0;
  while (cin >> ch)
    if (ch==c)
      return;
}

class Variable {
public:
  string name;
  double value;
};

Token_stream ts;
double expression();
vector<Variable> var_table;

double get_value(const string& s) {
  for (const Variable& v : var_table)
    if (v.name == s)
      return v.value;
  throw runtime_error("trying to read undefined variable " + s);
}
void set_value(const string& s, double d) {
  for (Variable& v : var_table) {
    if (v.name == s) {
      v.value = d;
      return;
    }
  }
}
bool is_declared(const string& var) {
  for (const Variable& v : var_table)
    if (v.name == var)
      return true;
  return false;
}
double define_name(const string& var, double val) {
  if (is_declared(var))
    throw runtime_error(var + " declared twice");
  var_table.push_back(Variable{var, val});
  return val;
}

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
    case name:
      return get_value(t.name);
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
double declaration() {
  Token t = ts.get();
  if (t.kind != name)
    throw runtime_error("name expected in declaration");

  Token t2 = ts.get();
  if (t2.kind != '=')
    throw runtime_error("= missing in declaration of " + t.name);
  double d = expression();
  define_name(t.name, d);
  return d;
}
double assignment() {
  Token t = ts.get();

  if (t.kind != name)
    throw runtime_error("name expected in assignment");

  Token t2 = ts.get();
  if (t2.kind != '=')
    throw runtime_error("= missing in assignment of " + t.name);

  const string var = t.name;
  if (!is_declared(var))
    throw runtime_error("variable " + var + " must be declared before assignment");

  double d = expression();
  set_value(var, d);
  return d;
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
double statement() {
  Token t = ts.get();
  switch (t.kind) {
    case let:
      return declaration();
    case name:
    {
      Token next = ts.get();
      ts.putback(t);
      ts.putback(next);

      if (next.kind == '=') {
        return assignment();
      } else {
        return expression();
      }
    }
    default:
      ts.putback(t);
      return expression();
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
    cout << result << statement() << '\n';
  } catch (exception& e) {
    cerr << e.what() << '\n';
    clean_up_mess();
  }
}

int main() {
  try {
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

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
