#include <vector>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main() {
  Application app;
  Point tl{x_max(), y_max()};
  Simple_window win{
    tl,
    x_max(),
    y_max(),
    "My window"
  };

  Rectangle r_1_1{Point{0, 0}, x_max()* 2 / 3, y_max() * 3 / 4};
  r_1_1.set_color(Color::red);
  win.attach(r_1_1);

  win.wait_for_button();
}
