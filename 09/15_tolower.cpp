#include <iostream>
#include <string>

using namespace std;

// > Prefer tolower() to toupper() because that works better for text in some natural languages, such as German, where
// > not every lowercase character has an uppercase equivalent.
// [PPP9.10.4]
void tolower(string& s) {
  for (char& x : s)
    x = tolower(x);
}

int main() {
  string s = "This string will be lowered - James Cagalawan";
  tolower(s);
  cout << s << '\n';
}
