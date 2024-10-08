#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum class TokenType{
  SHANT = 0,
  CANT = 1,
  WONT = 2,
  DONT = 3,
  SHOULDNT = 4,
  COULDNT = 5,
  WOULDNT = 6,
  QUOTED_PHRASE = 7,
  WORD = 8,
  WHITESPACE = 9,
  PUNCTUATION = 10,
  DOUBLE_QUOTE = 11,
};
unordered_map<TokenType, string> type_string{
  {TokenType::SHANT, "SHANT"},
  {TokenType::CANT, "CANT"},
  {TokenType::WONT, "WONT"},
  {TokenType::DONT, "DONT"},
  {TokenType::SHOULDNT, "SHOULDNT"},
  {TokenType::COULDNT, "COULDNT"},
  {TokenType::WOULDNT, "WOULDNT"},
  {TokenType::QUOTED_PHRASE, "QUOTED_PHRASE"},
  {TokenType::WORD, "WORD"},
  {TokenType::WHITESPACE, "WHITESPACE"},
  {TokenType::PUNCTUATION, "PUNCTUATION"},
  {TokenType::DOUBLE_QUOTE, "DOUBLE_QUOTE"},
};
ostream& operator<<(ostream& os, TokenType type) {
  return os << type_string[type];
}

struct Token {
  TokenType type;
  string lexeme;
};

const unordered_map<string, TokenType> keywords{
  {"shan't", TokenType::SHANT},
  {"can't", TokenType::CANT},
  {"won't", TokenType::WONT},
  {"don't", TokenType::DONT},
  {"shouldn't", TokenType::SHOULDNT},
  {"wouldn't", TokenType::WOULDNT},
  {"couldn't", TokenType::COULDNT},
};
const array<char, 6> punctuation{'.', ';', ',', '?', '-', '\''};

class Tokenizer {
public:
  Tokenizer(std::string line) : line_{std::move(line)} {
    for (char& c : line_) {
      c = static_cast<char>(tolower(c));
    }
  }

  vector<Token> scan_tokens() {
    while (!is_at_end()) {
      start_ = current_;
      scan_token();
    }
    return tokens_;
  }

private:
  void scan_token() {
    char c = advance();
    switch (c) {
      case '"':
      {
        double_quoted();
        break;
      }
      case '.':
      case ';':
      case ',':
      case'?':
      case '-':
      case '\'':
        add_token(TokenType::PUNCTUATION);
        break;
      case ' ':
      case '\t':
      case '\r':
      case '\n':
        add_token(TokenType::WHITESPACE);
        break;
      default:
      {
        if (is_alphanumeric(c)) word();
      }
    }
  }

  void add_token(TokenType type) {
    Token t{type, line_.substr(start_, current_ - start_)};
    tokens_.push_back(std::move(t));
  }
  void word() {
    while (is_word_part(peek())) {
      advance();
    }
    string word = line_.substr(start_, current_ - start_);
    if (keywords.contains(word)) {
      add_token(keywords.at(word));
    } else {
      add_token(TokenType::WORD);
    }
  }
  void double_quoted() {
    // Cache current_ in case we don't find a closing double quote.
    int current = current_;

    while (peek() != '"') {
      if (is_at_end()) {
        current_ = current;
        add_token(TokenType::DOUBLE_QUOTE);
        return;
      }
      advance();
    }
    // Consume the closing double quote.
    advance();

    add_token(TokenType::QUOTED_PHRASE);
  }
  bool is_at_end() {
    return current_ >= line_.size();
  }
  char advance() { return line_.at(current_++); }
  char peek() {
    if (is_at_end()) return '\0';
    return line_.at(current_);
  }
  bool is_digit(char c) { return ('0' <= c) && (c <= '9'); }
  bool is_alpha(char c) { return ('a' <= c) && (c <= 'z'); }
  bool is_alphanumeric(char c) { return is_alpha(c) || is_digit(c);}
  bool is_word_part(char c) { return is_alphanumeric(c) || c == '-' || c =='\''; }
  string line_;
  int start_ = 0;
  int current_ = 0;
  vector<Token> tokens_{};
};

string format(const Token& t) {
  switch (t.type) {

    case TokenType::SHANT:
      return "shall not";
    case TokenType::CANT:
      return "cannot";
    case TokenType::WONT:
      return "will not";
    case TokenType::DONT:
      return "do not";
    case TokenType::SHOULDNT:
      return "should not";
    case TokenType::COULDNT:
      return "could not";
    case TokenType::WOULDNT:
      return "would not";
    case TokenType::QUOTED_PHRASE:
    case TokenType::WORD:
    case TokenType::WHITESPACE:
    case TokenType::DOUBLE_QUOTE:
      return t.lexeme;
    case TokenType::PUNCTUATION:
      return " ";
  }
  return t.lexeme;
}

[[maybe_unused]]
void print_tokens(const vector<Token>& tokens) {
  for (const auto& token : tokens) {
    cout << token.type << " " << token.lexeme << '\n';
  }
  cout << '\n';
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Incorrect number of arguments.\n";
    cerr << "Usage: " << argv[0] << " file";
  }
  ifstream ifs{argv[1]};
  stringstream file;
  file << ifs.rdbuf();
  Tokenizer tokenizer{file.str()};
  vector<Token> tokens = tokenizer.scan_tokens();
  vector<string> words;
  for (const auto& token : tokens) {
    switch (token.type) {
      case TokenType::PUNCTUATION:
      case TokenType::WHITESPACE:
        continue;
      default:
        words.push_back(token.lexeme);
    }
  }
  ranges::sort(words);

  for (const auto& word : words) {
    cout << word << '\n';
  }
}
