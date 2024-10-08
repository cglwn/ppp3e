#include <fstream>
#include <iostream>
#include <vector>

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
  int input = 0;
  vector<Point> processed_points(7);
  ifstream ifs{"/tmp/mydata.txt"};
  while (input < 7) {
    ifs >> points[input];
    ++input;
  }

  for (const auto& p : points) {
    cout << p << '\n';
  }
}
