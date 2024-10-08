#include <vector>

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

  Rectangle r_1_1{Point{100, 100}, 100, 100};
  r_1_1.set_fill_color(Color::red);
  win.attach(r_1_1);
  Rectangle r_1_2{Point{200, 100}, 100, 100};
  r_1_2.set_fill_color(Color::white);
  win.attach(r_1_2);
  Rectangle r_1_3{Point{300, 100}, 100, 100};
  r_1_3.set_fill_color(Color::red);
  win.attach(r_1_3);

  Rectangle r_2_1{Point{100, 200}, 100, 100};
  r_2_1.set_fill_color(Color::white);
  win.attach(r_2_1);
  Rectangle r_2_2{Point{200, 200}, 100, 100};
  r_2_2.set_fill_color(Color::red);
  win.attach(r_2_2);
  Rectangle r_2_3{Point{300, 200}, 100, 100};
  r_2_3.set_fill_color(Color::white);
  win.attach(r_2_3);

  Rectangle r_3_1{Point{100, 300}, 100, 100};
  r_3_1.set_fill_color(Color::red);
  win.attach(r_3_1);
  Rectangle r_3_2{Point{200, 300}, 100, 100};
  r_3_2.set_fill_color(Color::white);
  win.attach(r_3_2);
  Rectangle r_3_3{Point{300, 300}, 100, 100};
  r_3_3.set_fill_color(Color::red);
  win.attach(r_3_3);

  win.wait_for_button();
}
