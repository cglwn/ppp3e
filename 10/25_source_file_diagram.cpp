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

  Rectangle point_box{Point{50, 50}, 180, 20};
  point_box.set_fill_color(Color::yellow);
  win.attach(point_box);
  Text point_header{Point{50, 35}, "Point.h:"};
  point_header.set_color(Color::white);
  win.attach(point_header);
  Text point_struct{Point{50, 50}, "struct Point { ... };"};
  point_struct.set_color(Color::blue);
  win.attach(point_struct);

  int graph_y = 200;
  Rectangle graph_gox{Point{50, graph_y}, 180, 20 + 15 * 3};
  graph_gox.set_fill_color(Color::yellow);
  win.attach(graph_gox);
  Text graph_header{Point{50, graph_y - 15}, "Graph.h:"};
  graph_header.set_color(Color::white);
  win.attach(graph_header);
  Text graph_comment{Point{50, graph_y}, "// Graphing interface"};
  win.attach(graph_comment);
  Text shape_struct{Point{50, graph_y+15}, "struct Shape { ... }"};
  win.attach(shape_struct);
  Text graph_ellipses{Point{50, graph_y+15*3}, "..."};
  win.attach(graph_ellipses);

  Line graph_to_point{Point{(50 + 90), graph_y}, Point{(50 + 90), 70}};
  win.attach(graph_to_point);

  win.wait_for_button();
}
