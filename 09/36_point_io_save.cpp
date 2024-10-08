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
  vector<Point> points(7);
  while (input < 7) {
    cout << "Enter a point (" << input << "/7):\n";
    cin >> points[input];
    ++input;
  }

  ofstream ofs{"/tmp/mydata.txt"};
  for (const Point& p : points) {
    ofs << p << '\n';
  }
}
