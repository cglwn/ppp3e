#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Reading {
  int hour;
  double temperature;
};

int main() {
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist {iname};
  if (!ist)
    throw runtime_error("can't open input file " + iname);

  string oname;
  cout << "Please enter name of output file: ";
  cin >> oname;
  ofstream ost {oname};
  if (!ost)
    throw runtime_error("can't open output file " + oname);

  vector<Reading> temps;
  int hour = -1;
  double temperature = -700;
  while (ist >> hour >> temperature) {
    if (hour < 0 || 23 < hour)
      throw runtime_error("hour out of range");
    temps.push_back(Reading{hour, temperature});
  }

  for (Reading x : temps)
    ost << '(' << x.hour << ',' << x.temperature << ")\n";
}
