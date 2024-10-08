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

  Rectangle frame{Point{100, 100}, 400, 200};
  win.attach(frame);

  Rectangle window1{Point{200,150}, 50, 50};
  win.attach(window1);

  Rectangle window2{Point{400, 150}, 50, 50};
  win.attach(window2);

  Rectangle door{Point{300, 180}, 60, 120};
  door.set_color(Color::dark_blue);
  win.attach(door);

  Closed_polyline roof;
  roof.add(Point{100, 100});
  roof.add(Point{500, 100});
  roof.add(Point{300, 50});
  win.attach(roof);

  Rectangle chimney{Point{150, 20}, 40, 80};
  chimney.set_color(Color::red);
  win.attach(chimney);

  win.wait_for_button();
}
