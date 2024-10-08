#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Name_pair {
  string name;
  double age;
};

class Name_pairs {
public:
  void read_names();
  void read_ages();
  void sort();
  const vector<Name_pair>& get_pairs() const { return pairs; }
private:
  vector<Name_pair> pairs;
};

void Name_pairs::read_names() {
  string n;
  while (cin >> n) {
    if (n == "x") {
      break;
    }
    pairs.emplace_back(n, -1);
  }
}
void Name_pairs::read_ages() {
  for (auto& pair : pairs) {
    cin >> pair.age;
  }
}
void Name_pairs::sort() {
  std::sort(
    pairs.begin(),
    pairs.end(),
    [&](const auto& l, const auto& r) {
      return l.name < r.name;
    });
}
ostream& operator<<(ostream& os, const Name_pairs& namePairs) {
  const vector<Name_pair>& pairs = namePairs.get_pairs();
  for (const auto& pair : pairs) {
    os << pair.name << ": " << pair.age << '\n';
  }
  return os;
}

int main() {
  Name_pairs namePairs;
  namePairs.read_names();
  namePairs.read_ages();
  cout << namePairs;
  cout << "\nSorting...\n";
  namePairs.sort();
  cout << namePairs;
}
