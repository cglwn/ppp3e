#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    for (const char& c : s) {
      cout << c << ": ";
      if (isspace(c)) { cout << "space "; }
      if (isalpha(c)) { cout << "alpha "; }
      if (isdigit(c)) { cout << "digit "; }
      if (isxdigit(c)) { cout << "xdigit "; }
      if (isupper(c)) { cout << "upper "; }
      if (islower(c)) { cout << "lower "; }
      if (isalnum(c)) { cout << "alnum "; }
      if (iscntrl(c)) { cout << "cntrl "; }
      if (ispunct(c)) { cout << "punct "; }
      if (isprint(c)) { cout << "print "; }
      if (isgraph(c)) { cout << "graph ";}
      cout << '\n';
    }
  }
}
