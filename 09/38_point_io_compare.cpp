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
  if (!(is >> left_paren)) {
    return is;
  }
  is >> p.x >> comma >> p.y >> right_paren;
  if ((left_paren != '(') || (comma != ',') || (right_paren != ')')) {
    return is;
  }
  return is;
}

bool operator==(const Point& p1, const Point& p2) {
  return p1.x == p2.x && p1.y == p2.y;
}

int main() {
  int input = 0;
  vector<Point> points(7);
  while (input < 7) {
    cout << "Enter a point (" << input << "/7):\n";
    cin >> points[input];
    ++input;
  }

  vector<Point> processed_points;
  ifstream ifs{"/tmp/mydata.txt"};
  Point p{};
  while (ifs >> p) {
    processed_points.push_back(p);
  }

  if (points.size() != processed_points.size()) {
    cout << "Something's wrong!\n";
  }

  for (int i = 0; i < points.size(); ++i) {
    if (points[i] != processed_points[i]) {
      cout << "Something's wrong!\n";
      return 1;
    }
  }
  cout << "Nothing's wrong!\n";
}
