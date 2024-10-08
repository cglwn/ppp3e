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

  Text a(Point{10, 10}, "J");
  a.set_font_size(150);
  a.set_color(Color::red);
  win.attach(a);

  Text j(Point{80, 10}, "C");
  j.set_font_size(150);
  j.set_color(Color::blue);
  win.attach(j);

  win.wait_for_button();
}
