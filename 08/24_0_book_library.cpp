#include <algorithm>
#include <chrono>
#include <exception>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using namespace chrono;

enum class Genre {
  Fiction,
  NonFiction,
  Periodical,
  Biography,
  Children,
};

unordered_map<Genre, string> genre_to_string {
  {Genre::Fiction, "Fiction"},
  {Genre::NonFiction, "NonFiction"},
  {Genre::Periodical, "Periodical"},
  {Genre::Biography, "Biography"},
  {Genre::Children, "Children"},
};

ostream& operator<<(ostream& os, Genre genre) {
  return os << genre_to_string[genre];
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
  string name() const { return name_; }
  string card_number() const { return card_number_; }
  double fees() const { return fees_; }
  void set_fees(double fees) { fees_ = fees; }
  bool is_owing() const { return fees_ != 0.0; }
private:
  string name_;
  string card_number_;
  double fees_;
};
bool operator==(const Patron& p1, const Patron& p2) {
  return p1.card_number() == p2.card_number();
}

class Transaction {
public:
  Transaction(Patron patron, Book book) : patron_{patron}, book_{book} {}
  Book book() const { return book_; }
  Patron patron() const { return patron_; }
private:
  Patron patron_;
  Book book_;
};
bool operator==(const Transaction& t1, const Transaction& t2) {
  return t1.book() == t2.book() && t1.patron() == t2.patron();
}

class Library {
public:
  void add_book(const Book& book) { books_.push_back(book); }
  void add_patron(const Patron& patron) { patrons_.push_back(patron); }
  void check_out(const Patron& patron, const Book& book);
  vector<Patron> get_all_owing();
private:
  vector<Book> books_;
  vector<Patron> patrons_;
  vector<Transaction> transactions_;
};

struct PatronNotFound : exception {};
struct BookNotFound : exception {};
struct PatronOwesFees : exception {};
struct TransactionNotFound : exception {};
void Library::check_out(const Patron& patron, const Book& book) {
  auto patron_it = find(patrons_.begin(), patrons_.end(), patron);
  if (patron_it == patrons_.end()) {
    throw PatronNotFound{};
  }
  auto book_it = find(books_.begin(), books_.end(), book);
  if (book_it == books_.end()) {
    throw BookNotFound{};
  }
  if (patron_it->is_owing()) {
    throw PatronOwesFees{};
  }
  transactions_.emplace_back(patron, book);
}
vector<Patron> Library::get_all_owing() {
  vector<Patron> owing_patrons;
  for (const auto& patron : patrons_) {
    if (patron.is_owing()) {
      owing_patrons.push_back(patron);
    }
  }
  return owing_patrons;
}

int main() {
  Book b1("1-2-3-4", "Words of Radiance", "Brandon Sanderson", August/15/2024, Genre::Fiction);
  cout << "b1=" << b1 << "\n\n";
  Book b2 = b1;
  cout << "b2=" << b2 << "\n\n";
  Book b3{"1-2-3-a", "The Sympathizer", "Viet Thanh Nguyen", August/16/2024, Genre::Fiction};
  cout << "b3=" << b3 << "\n\n";
  cout << "b1==b2=" << boolalpha << (b1 == b2) << '\n';
  cout << "b1==b3=" << boolalpha << (b1 == b3) << '\n';

  Patron p{"James", "271310", 0.0};
  Library l;
  l.add_patron(p);
  l.add_book(b1);
  l.add_book(b2);
  l.add_book(b3);
  cout << "l.get_all_owing().size()=" <<
       l.get_all_owing().size() << '\n';

  try {
    l.check_out(p, b1);
  } catch(exception& e) {
    cerr << "Could not check out book." << '\n';
    cerr << e.what() << '\n';
  }
  l.check_out(p, b2);
}
