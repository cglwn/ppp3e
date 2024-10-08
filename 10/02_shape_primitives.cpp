#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main() {
  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Canvas"};

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};

  win.attach(xa);
  win.set_label("X axis");
  win.wait_for_button();
}
