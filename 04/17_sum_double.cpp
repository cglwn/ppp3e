#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <version>

using namespace std;

int main() {
  cout << "Please enter the number of values you want to sum:\n";
  int n;
  cin >> n;

  vector<double> nums(n);

  cout << "Please enter some integers (press '|' to stop):";
  string input;
  int num_input = 0;
  while (cin >> input) {
    if (input == "|") {
      break;
    }
    if (num_input >= n) {
      throw runtime_error("too many values");
    }
    istringstream iss{input};
    if (!(iss >> nums[num_input])) {
      throw runtime_error("input cannot be represented as double");
    }
    ++num_input;
  }

  if (num_input < n) {
    throw runtime_error("not enough numbers");
  }
#ifdef __cpp_lib_ranges_fold
  // libc++ does not have the range fold algorithms.
  const double sum = std::ranges::fold_left(nums, 0.0);
#else
  const double sum = accumulate(begin(nums), end(nums), 0.0);
#endif
  if (sum > numeric_limits<double>::max() || sum < numeric_limits<double>::min()) {
    throw runtime_error("sum cannot be represented as int");
  }
  cout << "The sum of the first " << n << " numbers ( ";
  for (const auto num : nums) {
    cout << num << " ";
  }
  cout << ") is " << sum << '\n';

  cout << "Differences are ( ";
  vector<double> differences;
  for (int i = 0; (i + 1) < nums.size(); ++i) {
    differences.emplace_back(nums[i+1] - nums[i]);
    cout << differences.back() << ' ';
  }
  cout << ")\n";

}
