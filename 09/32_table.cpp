#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int max_line_length = 74;

int main() {
  vector<string> family_names{"Uzumaki", "Uchiha", "Haruno", "Lee", "Abe"};
  vector<string> given_names{"Naruto", "Sasuke", "Sakura", "Rock", "Shinzo"};
  vector<string> telephone_numbers{
    "(123) 456-7890",
    "(234) 567-7891",
    "(345) 678-9012",
    "(456) 789-0123",
    "(567) 890-1234",
  };
  vector<string> email_addresses {
    "uzumaki.naruto@gmail.com",
    "uchiha.sasuke@yahoo.com",
    "haruno.sakura@protonmail.com",
    "lee.rock@hotmail.com",
    "shinzo.abe@yahoo.jp",
  };
  cout << "Family Name" << " | "
       << "Given Name" << " | "
       << "Telephone Number" << " | "
       << "Email Address" << "\n";
  for (int i = 0; i < max_line_length; ++i) {
    cout << "-";
  }
  cout << '\n';

  for (int i = 0; i < 5; ++i) {
    cout << setw(11) << family_names[i] << " | "
         << setw(10) << given_names[i] << " | "
         << setw(16) << telephone_numbers[i] << " | "
         << email_addresses[i] << "\n";
  }
}
