#include <iostream>

using namespace std;

struct Date {
  int y;
  int m;
  int d;
  Date (int y, int m, int d) {}
  void add_day(int n) {}
};

int main() {
  Date today{2000, 12, 31};
}
