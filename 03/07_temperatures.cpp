#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> temps;
  for (double temp; cin >> temp;)
    temps.push_back(temp);

  // compute mean temperature
  double sum = 0;
  for (double x : temps)
    sum += x;
  cout << "Average temperature: " << sum / temps.size() << '\n';

  // compute median temperature
  ranges::sort(temps);
  cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}
