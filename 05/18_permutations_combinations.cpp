// A calculator for permutations and combinations.
//
// Requirements
// ------------
// The program will prompt the user for two numbers n
// and k by outputting:
//   "Please enter two integers n and k:"
//
// These two inputs are read into `int`s, if the inputs
// aren't both integers then the program will give an
// error saying "input was not an int".
//
// If both inputs are ints then the program will prompt
// the user for if they want to calculate permutations
// or combinations.
//   "Do you want to calculate (p)ermutations or (c)ombinations?"
// If the user enters 'p' then it calculates permutations.
// If the user enters 'c' then it calculates combinations.
// If the user enters something else, it will give an
// error saying "must input either 'p' or 'c'"
//
//
// Pseudocode
// ----------
// In pseudocode the program can be expressed as
//   tell user to input two integers
//   read n and k from the user
//   while n and k aren't integers
//     tell user n and k need to be integers
//   tell user to input 'p' or 'c' to select the calculation type
//   while the input wasn't 'p' or 'c'
//     continue telling the user to input a 'p' or 'c'
//   if the user enters p, calculate the permutations using the (a!)/((a-b)!) formula
//   if the user enters 'c', calculate the combinations using the (P(a,b))/(b!) formula
//   print out the result of the calculation

#include <iostream>
#include <stdexcept>

using namespace std;

class UnknownOperation : public exception {};

int factorial(const int x) {
  int fact_x = 1;
  for (int i = 1; i <= x; ++i) {
    fact_x *= i;
  }
  return fact_x;
}

int permutations(const int a, const int b) {
  return factorial(a) / factorial(a - b);
}

int combinations(const int a, const int b) {
  return permutations(a, b) / factorial(b);
}

int main() {
  while (true) try {
    int n;
    int k;

    cout << "Enter two integers n and k to calculate either nCk or nPk:\n";
    while (!(cin >> n >> k) && (k > n)) {
      cerr << "Please enter two integers n and k (1 <= k <= n):\n";
    }

    char operation;
    cout << "Do you want to calculate (p)ermutations or (c)ombinations?\n";
    while (true) try {
      cin >> operation;
      switch (operation) {
        case 'p':
          cout << permutations(n, k) << '\n';
          break;
        case 'c':
          cout << combinations(n, k) << '\n';
        default:
          throw UnknownOperation();
      }
      break;
    } catch (UnknownOperation& e) {
      cerr << e.what() << "\nenter 'p' for permutations or 'c' for combinations\n";
    } catch (exception& e) {
      cerr << e.what() << '\n';
    }

  } catch (exception& e) {
    cerr << e.what() << '\n';
  } catch (...) {
    return 1;
  }
}
