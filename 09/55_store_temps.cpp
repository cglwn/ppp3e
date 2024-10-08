// Write a program that creates a file of data in the
// form of the temperature Reading type defined in §9.3.2.
// For testing, fill the file with at least 50 "temperature
// readings." Call this program store_temps.cpp and the file
// it creates raw_temps.txt.
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Reading {
  int hour;
  double temperature;
};

ostream& operator<<(ostream& os, const Reading& r) {
  return os << r.hour << " " << r.temperature;
}

int main() {
  ofstream ofs{"/tmp/raw_temps.txt"};
  vector<Reading> readings(50);
  for (int i = 0; i < 50; ++i) {
    int hour;
    double temperature;
    cin >> hour >> temperature;
    readings[i].hour = hour;
    readings[i].temperature = temperature;
  }
  for (const auto& reading : readings) {
    ofs << reading << '\n';
  }
}
