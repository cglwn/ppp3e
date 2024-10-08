#include <iostream>
#include <map>

using namespace std;

int main() {
  cout << "Enter a number and we'll find all the primes less than it: \n";
  int n = 30;
  cin >> n;
  map<int, bool> marked;
  for (int i = 2; i <= n; ++i) {
    marked[i] = false;
  }

  int p = 2;

  while (true) {
    cout << p << '\n';
    int k = 2;
    while (k*p <= n) {
      marked.at(k*p) = true;
      k += 1;
    }
    bool no_marked_gt_p = true;
    int first_marked = -1;
    for (int i = p+1; i <= n; ++i) {
      if (!marked.at(i)) {
        no_marked_gt_p = false;
        first_marked = i;
        break;
      }
    }
    if (no_marked_gt_p) {
      break;
    } else {
      p = first_marked;
    }
  }
}
