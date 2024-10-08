#include "Simple_window.h"
#include "Graph.h"

using namespace std;

double dsin(double d) { return sin(d); }

int main() {
  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Canvas"};

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};

  win.attach(xa);
  win.set_label("X axis");
  win.wait_for_button();

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::cyan);
  ya.label.set_color(Color::dark_red);

  win.attach(ya);
  win.set_label("Y axis");
  win.wait_for_button();

  Function sine{dsin, 0, 100, Point{20, 150}, 1000, 50, 50};

  win.attach(sine);
  win.set_label("Sine");
  win.wait_for_button();

  sine.set_color(Color::blue);

  Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});
  poly.set_color(Color::red);
  win.attach(poly);
  win.set_label("Triangle");
  win.wait_for_button();

  Rectangle r{Point{200, 200}, 100, 50};

  win.attach(r);
  win.set_label("Rectangle");
  win.wait_for_button();
}
