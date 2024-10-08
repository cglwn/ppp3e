#include "PPP.h"

char ask_user(string question) {
  cout << question << "? (yes or no)\n";
  string answer;
  cin >> answer;
  if (answer=="y" || answer=="yes")
    return 'y';
  if (answer=="n" || answer=="no")
    return 'n';
  return 'b';
}

int area(int length, int width) {
  if (length <= 0 || width <= 0)
    return -1;
  return length*width;
}

int checked_area(int length, int width) {
  const auto a = area(length, width);
  if (a != -1) {
    return a;
  }
  error("failed to calculate area");
}

int main() {}
