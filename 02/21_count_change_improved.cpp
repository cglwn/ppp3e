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

  const string pennies_counter = pennies == 1 ? "penny" : "pennies";
  const string nickels_counter = nickels == 1 ? "nickel" : "nickels";
  const string dimes_counter = dimes == 1 ? "dime" : "dimes";
  const string quarters_counter = quarters == 1 ? "quarter" : "quarters";
  const string half_dollars_counter = half_dollars == 1 ? "half dollar" : "half dollars";
  cout << "You have " << pennies << " " << pennies_counter << ".\n"
       << "You have " << nickels << " " << nickels_counter << ".\n"
       << "You have " << dimes << " " << dimes_counter << ".\n"
       << "You have " << quarters << " " << quarters_counter << ".\n"
       << "You have " << half_dollars << " " << half_dollars_counter << ".\n";
  const int value = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars;
  const int dollars = value / 100;
  const int cents = value % 100;
  cout << "The value of all of your coins is $" << dollars << "." << (cents < 10 ? "0" : "") << cents << ".\n";
}
