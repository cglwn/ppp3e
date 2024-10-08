#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <double> temps;
    for (double temp; cin >> temp; )
      temps.push_back(temp);

    ranges::sort(temps);

    cout << "Median temperature: " << (temps[0] + temps.back())/2 << '\n';
}