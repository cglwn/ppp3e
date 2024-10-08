#include <numbers>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main() {
  Application app;
  Point tl{900, 500};
  const int w = 900;
  const int h = 900;
  Simple_window win{
    tl,
    w,
    h,
    "My window"
  };
  const int mid_x = w / 2;
  const int mid_y = h / 2;
  const int n_polygons = 20;
  vector<Polygon> polygons(n_polygons);
  for (int sides = 3; sides < (3 + n_polygons); ++sides) {
    for (int i = 0; i < sides; ++i) {
      const double theta = i * 2 * numbers::pi_v<double> / sides;
      const int x = static_cast<int>(mid_x + cos(theta) * 10 * sides);
      const int y = static_cast<int>(mid_y + sin(theta) * 10 * sides);
      polygons[sides - 3].add(Point{x, y});
    }
  }

  for (auto& p : polygons) {
    win.attach(p);
  }

  win.wait_for_button();
}
