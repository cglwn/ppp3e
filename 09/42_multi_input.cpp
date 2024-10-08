#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum class Type {
  Decimal = 0,
  Octal = 1,
  Hexadecimal = 2,
};

struct Conversion {
  string input;
  Type type;
  int number;
};

ostream& operator<<(ostream& os, const Conversion& conversion) {
  switch (conversion.type) {
    case Type::Decimal:
      os << setw(6) << conversion.input
         << " decimal     converts to "
         << setw(6) << conversion.number;
      break;
    case Type::Octal:
      os << setw(6) << conversion.input
         << " octal       converts to "
         << setw(6) << conversion.number;
      break;
    case Type::Hexadecimal:
      os << setw(6) << conversion.input
         << " hexadecimal converts to "
         << setw(6) << conversion.number;
      break;
  }
  os << " decimal";
  return os;
}

int main() {
  cout << "Enter a number in decimal, octal (with a leading zero), or\n"
       << "hexadecimal (with a leading 0x):\n";
  vector<Conversion> conversions;
  while (true) {
    string s;
    if (!(cin >> s)) {
      break;
    }

    Type type;
    int i;

    if (s.size() > 1 && s[0] == '0' && s[1] == 'x') {
      type = Type::Hexadecimal;
      const string digits = s.substr(2, s.size() - 2);
      istringstream iss{digits};
      iss >> hex >> i;
    } else if (s.size() > 0 && s[0] == '0') {
      type = Type::Octal;
      string digits = s.substr(1, s.size() - 1);
      istringstream iss{digits};
      iss >> oct >> i;
    } else {
      type = Type::Decimal;
      istringstream iss{s};
      if (!(iss >> i)) {
        break;
      }
    }
    Conversion conversion{s, type, i};
    conversions.push_back(std::move(conversion));
  }
  for (const auto& conversion : conversions) {
    cout << conversion << '\n';
  }
}
