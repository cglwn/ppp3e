#include "PPP.h"

constexpr int frame_width = 2;

// calculate area of a rectangle
int area(int length, int width) {
  return length * width;
}

// calculate area within frame
int framed_area(int x, int y) {
  return area(x-frame_width, y-frame_width);
}

void test(int x, int y, int z) {
  if (x <= 0 || y <= 0)
    error("non-positive area() argument");
  int area1 = area(x, y);
  if (1-frame_width<=0 || z-frame_width<=0)
    error("non-positive argument for area() called by framed area()");
  int area2 = framed_area(1, z);
  if (y-frame_width<=0 || z-frame_width<=0)
    error("non-positive argument for area() called by framed area()");
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3; // convert to double to get floating point division
}

int main() {
  test(-1, 2, 3);
}
