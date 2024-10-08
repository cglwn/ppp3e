#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  cout << "Enter distances: \n";
  int count = 0;
  double sum = 0.0;
  double max_dist = numeric_limits<double>::min();
  double min_dist = numeric_limits<double>::max();
  for (double dist; cin >> dist; count++) {
    sum += dist;
    max_dist = max(max_dist, dist);
    min_dist = min(min_dist, dist);
  }

  cout << "Sum:\t" << sum << '\n';
  cout << "Max Dist:\t" << max_dist << '\n';
  cout << "Min Dist:\t" << min_dist << '\n';
  cout << "Mean Dist:\t" << sum / count << '\n';
}
