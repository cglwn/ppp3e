#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int not_a_reading = -7777;
const int not_a_month = -1;

void end_of_loop(istream& ist, char term, const string& message) {
  if (ist.fail()) {
    ist.clear();
    char ch = 0;
    if (ist >> ch && ch == term)
      return;
    throw runtime_error(message);
  }
}

struct Day {
  vector<double> temp = vector<double>(24, not_a_reading);
};

struct Month {
  int month = not_a_month;           //[0:11] January is 0
  vector<Day> day = vector<Day>(32); // [1:31] one vector of readings per day
};

struct Year {
  int year;
  vector<Month> month = vector<Month>(12);
};

struct Reading {
  int day;
  int hour;
  double temperature;
};

istream& operator>>(istream& is , Reading& r) {
  char ch1;
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  char ch2;
  if ((is >> r.day >> r.hour >> r.temperature >> ch2) && ch2 != ')')
    throw runtime_error("bad reading");
  return is;
}

vector<string> month_input_tbl = {
  "-not a month-",
  "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec",
};
int month_to_int(string s) {
  for (int i = 1; i < 13; ++i)
    if (month_input_tbl[i] == s)
      return i;
  return 0;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;
bool is_valid(const Reading& r) {
  if (r.day < 1 || 31 < r.day)
    return false;
  if (r.hour < 0 || 23 < r.hour)
    return false;
  if (r.temperature < implausible_min || implausible_max < r.temperature)
    return false;
  return true;
}
istream& operator>>(istream& is, Month& m) {
  char ch = 0;
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if (!is || month_marker != "month")
    throw runtime_error("bad start of month");
  m.month = month_to_int(mm);

  int duplicates = 0;
  int invalids = 0;
  for (Reading r; is >> r;) {
    if (is_valid(r)) {
      if (m.day[r.day].hour[r.hour] != not_a_reading)
        ++duplicates;
      m.day[r.day].hour[r.hour] = r.temperature;
    }
    else
      ++invalids;
  }
  if (invalids)
    throw runtime_error("invalid readings in month ");
  if (duplicates)
    throw runtime_error("duplicate readings in month");
  end_of_loop(is, '}', "bad end of month");
  return is;
}
istream& operator>>(istream& is, Year& y) {
  char ch = 0;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string year_marker;
  int yy = -1;
  is >> year_marker >> yy;
  if (!is || year_marker != "year")
    throw runtime_error("bad start of year");
  y.year = yy;

  while (true) {
    Month m;
    if (!(is >> m))
      break;
    y.month[m.month] = m;
  }

  end_of_loop(is, '}', "bad end of year");
  return is;
}
void print_year(ostream& os, Year& year) {
  os << year.year << '\n';
}
int main() {
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs {iname};
  if (!ifs)
    throw runtime_error("can't open input file " + iname);

  // throw for bad()
  ifs.exceptions(ifs.exceptions() | ios::badbit);

  // open an output file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs{oname};
  if (!ofs)
    throw runtime_error("can't open output file " + oname);

  vector<Year> ys;
  while (true) {
    Year y;
    if (!(ifs >> y))
      break;
    ys.push_back(y);
  }
  cout << "read " << ys.size() << " years of readings\n";

  for (Year& y : ys)
    print_year(ofs, y);
}
