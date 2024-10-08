#include <numbers>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

// a, b, m, n: Parameters to a superellipse |x/a|ᵐ + |y/b|ⁿ = 1
void superellipse(int a, int b, int m, int n, int N) {
  for (int i = 0; i < N; ++i) {
    const double theta = i * 2 * numbers::pi_v<double> / N;

  }
}

int main() {
  Application app;
  Point tl{900, 500};
  Simple_window win{
    tl,
    600,
    400,
    "My window"
  };
  win.wait_for_button();
}
