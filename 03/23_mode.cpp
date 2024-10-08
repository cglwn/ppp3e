#include <iostream>
#include <map>

using namespace std;

int main() {
  cout << "Enter ints: \n";
  map<int, int> counts;
  for (int i; cin >> i; counts[i]++) {

  }
  int mode = -1;
  int most_counts = 0;
  for (const auto [val, count] : counts) {
    if (count > most_counts) {
      mode = val;
      most_counts = count;
    }
  }
  cout << "The mode is " << mode << '\n';
}
