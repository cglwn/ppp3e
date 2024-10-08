#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main() {
  Application app;
  Point tl{900, 500};
  Simple_window win{
    tl,
    600,
    400,
    "My window"
  };

  Rectangle r(Point{10, 10}, 10, 10);
  r.set_color(Color::red);
  win.attach(r);

  Closed_polyline r2;
  r2.add(Point{30, 30});
  r2.add(Point{30, 40});
  r2.add(Point{40, 40});
  r2.add(Point{40, 30});
  r2.set_color(Color::blue);
  win.attach(r2);

  win.wait_for_button();
}
