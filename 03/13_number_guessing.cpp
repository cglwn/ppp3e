#include <iostream>

using namespace std;

int main() {
  int lo = 1;
  int hi = 100;
  while (lo < hi) {
    int mid = (lo+hi)/2;
    cout << "Is your number less than " << mid << " (y/n)?\n";
    char response;
    cin >> response;
    switch(response) {
      case 'y':
        hi = mid - 1;
        break;
      case 'n':
        lo = mid;
    }
  }
  cout << "Your number is " << (lo+hi)/2 << '\n';
}
