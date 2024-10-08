#include <chrono>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;
using namespace chrono;

enum class Genre {
  Fiction,
  NonFiction,
  Periodical,
  Biography,
  Children,
};

ostream& operator<<(ostream& os, Genre genre) {
  if (genre == Genre::Fiction) {
    return os << "Fiction";
  } else if (genre == Genre::NonFiction) {
    return os << "NonFiction";
  } else if (genre == Genre::Periodical) {
    return os << "Periodical";
  } else if (genre == Genre::Biography) {
    return os << "Biography";
  } else if (genre == Genre::Children) {
    return os << "Children";
  }
  return os;
}

class Book {
public:
  Book(string isbn,
       string title,
       string author,
       year_month_day copyright_date,
       Genre genre) : isbn_{std::move(isbn)}
       , title_{std::move(title)}
       , author_{std::move(author)}
       , copyright_date_{copyright_date}
       , genre_{genre}{
    if (!is_valid()) {
      throw runtime_error("format invalid");
    }
  }
  string isbn() const { return isbn_; }
  string title() const { return title_; }
  string author() const { return author_; }
  year_month_day copyright_date() const { return copyright_date_; }
  Genre genre() const { return genre_; }
  bool checked_out() const { return checked_out_; }
private:
  bool is_valid();
  string isbn_;
  string title_;
  string author_;
  year_month_day copyright_date_;
  Genre genre_;
  bool checked_out_ = false;
};
bool Book::is_valid() {
  istringstream iss{isbn_};
  int n;
  if (!(iss >> n)) return false;
  char c;
  if (!(iss >> c) || c != '-') return false;
  if (!(iss >> n)) return false;
  if (!(iss >> c) || c != '-') return false;
  if (!(iss >> n)) return false;
  if (!(iss >> c) || c != '-') return false;
  if (!(iss >> c)) return false;
  if (!isdigit(c) && !isalpha(c)) return false;
  return true;
}
bool operator==(const Book& b1, const Book& b2) {
  return b1.isbn() == b2.isbn();
}
ostream& operator<<(ostream& os, const Book& book) {
  return os << book.title() << '\n' << book.author() << '\n' << book.isbn() << '\n' << book.genre();
}

class Patron {
public:
  Patron(string name, string card_number, double fees) :
    name_{std::move(name)}
    , card_number_{std::move(card_number)}
    , fees_{fees} {}
  string name() { return name_; }
  string card_number() { return card_number_; }
  double fees() { return fees_; }
  void set_fees(double fees) { fees_ = fees; }
  bool is_owing() { return fees_ != 0.0; }
private:
  string name_;
  string card_number_;
  double fees_;
};

int main() {
  Book b1("1-2-3-4", "Words of Radiance", "Brandon Sanderson", August/15/2024, Genre::Fiction);
  cout << "b1=" << b1 << "\n\n";
  Book b2 = b1;
  cout << "b2=" << b2 << "\n\n";
  Book b3{"1-2-3-a", "The Sympathizer", "Viet Thanh Nguyen", August/16/2024, Genre::Fiction};
  cout << "b3=" << b3 << "\n\n";
  cout << "b1==b2=" << boolalpha << (b1 == b2) << '\n';
  cout << "b1==b3=" << boolalpha << (b1 == b3) << '\n';
}
