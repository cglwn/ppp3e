#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
  random_device rd;
  default_random_engine engine(rd());
  uniform_int_distribution dist(0, 2);

  while (true) {
    cout << "Choose (r)ock, (p)aper, or (s)cissors: \n";
    char user_rps;
    cin >> user_rps;
    const array<char, 3> to_rps{'r', 'p', 's'};

    if (find(to_rps.begin(), to_rps.end(), user_rps) == to_rps.end()) {
      throw runtime_error("unknown input, enter r, p, or s");
    }

    const char ai_rps = to_rps[dist(engine)];
    cout << ai_rps << "!\n";
    if (user_rps == ai_rps) {
      cout << "Tie\n";
    } else if (
      (user_rps == 'r' && ai_rps == 's') ||
      (user_rps == 'p' && ai_rps == 'r') ||
      (user_rps == 's' && ai_rps == 'p')) {
      cout << "You win\n";
    } else {
      cout << "You lose\n";
    }
  }
}
