#include "PPP.h"
// calculate area of a rectangle
int area(int length, int width) {
  if (length<=0 || width<=0)
    error("non-positive area() argument");
  return length * width;
}

// calculate area within frame
int framed_area(int x, int y) {
  constexpr int frame_width = 2;
  if (x-frame_width<=0 || y-frame_width<=0)
    error("non-positive area() argument called by framed_area()");
  return area(x-frame_width, y-frame_width);
}

void test(int x, int y, int z) {
  int area1 = area(x, y);
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3; // convert to double to get floating point division
}

int main() {
  test(-1, 2, 3);
}
