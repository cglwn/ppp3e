#include <iostream>

using namespace std;

int main() {
  cout << "How many pennies do you have?\n";
  int pennies;
  cin >> pennies;
  cout << "How many nickels do you have?\n";
  int nickels;
  cin >> nickels;
  cout << "How many dimes do you have?\n";
  int dimes;
  cin >> dimes;
  cout << "How many quarters do you have?\n";
  int quarters;
  cin >> quarters;
  cout << "How many half dollars do you have?\n";
  int half_dollars;
  cin >> half_dollars;

  cout << "You have " << pennies << " pennies.\n"
       << "You have " << nickels << " nickels.\n"
      << "You have " << dimes << " dimes.\n"
      << "You have " << quarters << " quarters.\n"
      << "You have " << half_dollars << " half dollars.\n";
  const int value = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars;
  cout << "The value of all of your coins is " << value << " cents.\n";
}
