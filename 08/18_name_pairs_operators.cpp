#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Name_pairs {
public:
  void read_names();
  void read_ages();
  void sort();
  const vector<string>& get_names() const { return name; }
  const vector<double>& get_ages() const { return age; }
private:
  vector<string> name;
  vector<double> age;
};

void Name_pairs::read_names() {
  string n;
  while (cin >> n) {
    if (n == "x") {
      break;
    }
    name.push_back(n);
  }
}
void Name_pairs::read_ages() {
  age.reserve(name.size());
  for (int i = 0; i < name.size(); ++i) {
    int n;
    cin >> n;
    age.push_back(n);
  }
}
void Name_pairs::sort() {
  vector<int> indices(name.size());
  iota(indices.begin(), indices.end(), 0);

  std::sort(
    indices.begin(),
    indices.end(),
    [&](int i, int j) {
      return name[i] < name[j];
    });
  vector<string> name_sorted;
  vector<double> age_sorted;
  for (const int i : indices) {
    name_sorted.push_back(name[i]);
    age_sorted.push_back(age[i]);
  }
  name = name_sorted;
  age = age_sorted;
}
ostream& operator<<(ostream& os, const Name_pairs& namePairs) {
  const vector<string>& name = namePairs.get_names();
  const vector<double>& age = namePairs.get_ages();
  for (int i = 0; i < name.size(); ++i) {
    os << name[i] << ": " << age[i] << '\n';
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
