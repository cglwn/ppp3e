#include <chrono>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;
using namespace chrono;

class Book {
public:
  Book(string isbn,
       string title,
       string author,
       year_month_day copyright_date) : isbn_{std::move(isbn)}
       , title_{std::move(title)}
       , author_{std::move(author)}
       , copyright_date_{copyright_date} {
    if (!is_valid()) {
      throw runtime_error("format invalid");
    }
  }
  string isbn() { return isbn_; }
  string title() { return title_; }
  string author() { return author_; }
  year_month_day copyright_date() { return copyright_date_; }
  bool checked_out() const { return checked_out_; }
private:
  bool is_valid();
  string isbn_;
  string title_;
  string author_;
  year_month_day copyright_date_;
  bool checked_out_ = false;
};
bool Book::is_valid() {
  istringstream iss{isbn_};
  int n;
  if (!(iss >> n)) {
    return false;
  }
  char c;
  if (!(iss >> c) || c != '-') {
    return false;
  }
  if (!(iss >> n)) {
    return false;
  }
  if (!(iss >> c) || c != '-') {
    return false;
  }
  if (!(iss >> n)) {
    return false;
  }
  if (!(iss >> c) || c != '-') {
    return false;
  }
  if (!(iss >> c)) {
    return false;
  }
  if (!isdigit(c) && !isalpha(c)) {
    return false;
  }
  return true;
}

int main() {
  try {
    Book("1-2-3-$", "Way of Kings", "Brandon Sanderson", August/15/2024);
  } catch (runtime_error& error) {
    cout << "Error caught\n";
  }
  Book("1-2-3-4", "Words of Radiance", "Brandon Sanderson", August/15/2024);
}
