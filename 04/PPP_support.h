namespace PPP {

// error handling
inline void error(const std::string& s) {
  throw std::runtime_error(s);
}

inline void error(const std::string& s, const std::string& s2) {
  error(s + s2);
}

inline void error(const std::string& s, int i) {
  std::ostringstream os;
  os << s << ": " << i;
  error(os.str());
}

}
