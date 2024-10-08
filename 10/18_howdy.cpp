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

  Rectangle r(Point{10, 10}, 100, 30);
  r.set_color(Color::red);
  win.attach(r);

  Text t(Point{30, 15}, "Howdy!");
  t.set_color(Color::red);
  win.attach(t);

  win.wait_for_button();
}
