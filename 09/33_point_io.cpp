#include <iostream>
#include <sstream>

using namespace std;

struct Point {
  double x;
  double y;
};

ostream& operator<<(ostream& os, const Point& p) {
  return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p) {
  char left_paren;
  char comma;
  char right_paren;
  is >> left_paren >> p.x >> comma >> p.y >> right_paren;
  if ((left_paren != '(') || (comma != ',') || (right_paren != ')')) {
    throw runtime_error("Bad format for point");
  }
  return is;
}

int main() {
  istringstream iss{"(2,3)"};
  Point p{};
  iss >> p;
  cout << p;
}
