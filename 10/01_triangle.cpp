#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main() {
  using namespace Graph_lib;

  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Canvas"};

  Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 10});
  poly.add(Point{400, 200});
  poly.set_color(Color::red);

  win.attach(poly);

  win.wait_for_button();
}
