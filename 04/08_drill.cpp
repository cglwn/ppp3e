#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() try {
#ifdef q01
  Cout << "Success!\n";
#endif
#ifdef q02
  cout << "Success!\n";
#endif
#ifdef q03
  cout << "Success" << !\n"
#endif
#ifdef q04
  cout << success << '\n';
#endif
#ifdef q05
  string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
#endif
#ifdef q06
  vector<int> v(10); v(5) = 7; if(v(5) != 7) cout << "Success!\n";
#endif
#ifdef q07
  if (cond) cout << "Success!\n"; else cout << "Fail!\n";
#endif
#ifdef q08
  bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
#endif
#ifdef q09
  string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
#endif
#ifdef q10
  string s = "ape"; if (s=="fool") cout << "Success!\n";
#endif
#ifdef q11
  string s = "ape"; if (s=="fool") cout < "Success!\n";
#endif
#ifdef q12
  string s = "ape"; if (s+"fool") cout < "Success!\n";
#endif
#ifdef q13
  vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
#endif
#ifdef q14
  vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
#endif
#ifdef q15
  string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
#endif
#ifdef q16
  if (true) then cout << "Success!\n"; else cout << "Fail!\n";
#endif
#ifdef q17
  int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
#endif
#ifdef q18
  string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];
#endif
#ifdef q19
  vector v(5); for (int i = 0; i<=v.size(); ++i); cout << "Success!\n";
#endif
#ifdef q20
  int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
#endif
#ifdef q21
  int x = 2; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";
#endif
#ifdef q22
  string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
#endif
#ifdef q23
  int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
#endif
#ifdef q24
  int x = 4; double d = 5/(x-2); if (d = 2*x+0.5) cout << "Success!\n";
#endif
#ifdef q25
  cin << "Success!\n";
#endif
  return 0;
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
