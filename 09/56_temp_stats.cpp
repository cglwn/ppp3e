#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Reading {
  int hour;
  double temperature;
};

int main() {
  ifstream ifs{"/tmp/raw_temps.cpp"};
  vector<Reading> readings(50);
  double sum = 0;
  for (int i = 0; i < 50; ++i) {
    int hour;
    double temperature;
    ifs >> hour >> temperature;
    cout << hour << " " << temperature << '\n';
    readings[i].hour = hour;
    readings[i].temperature = temperature;
    sum += temperature;
  }
  ranges::sort(readings, [](const Reading& r1, const Reading& r2){ return r1.temperature < r2.temperature; });
  cout << "The mean temperature is " << sum / 50 << ".\n";
  cout << "The median temperature is " << readings[24].temperature << ".\n";
}
