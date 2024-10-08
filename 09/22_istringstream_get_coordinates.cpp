#include <iostream>
#include <sstream>

using namespace std;

struct Point {
  double x;
  double y;
};

ostream& operator<<(ostream& os, const Point p) {
  return os << '(' << p.x << ',' << p.y << ')';
}

Point get_coordinates(const string& s) {
  istringstream is{s};
  Point xy;
  char left_paren, ch, right_paren;
  is >> left_paren >> xy.x >> ch >> xy.y >> right_paren;
  if (!is || left_paren != '(' || ch != ',' || right_paren != ')')
    throw runtime_error("format error: " + s);
  return xy;
}

int main() {
  auto c1 = get_coordinates("(2, 3)");
  cout << c1 << '\n';
  auto c2 = get_coordinates("( 200,300)");
  cout << c2 << '\n';
  try {
    auto c3 = get_coordinates("100,400");
    cout << c3 << '\n';
  } catch(...) {
    cout << "Bad format caught!\n";
  }
}
