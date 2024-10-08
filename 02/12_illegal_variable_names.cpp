int main() {
#if false
  /*
   * 12_illegal_variable_names.cpp: In function ‘int main()’:
   * 12_illegal_variable_names.cpp:3:14: error: expected unqualified-id before ‘=’ token
   *     3 |   int double = 3;
   *       |              ^
   */
  int double = 3;
  int template = 3;
  int auto = 3;
  int + = 3;
  /*
   * 12_illegal_variable_names.cpp: In function ‘int main()’:
   * 12_illegal_variable_names.cpp:3:3: error: expected primary-expression before ‘int’
   *     3 |   int class = 3;
   *       |   ^~~
   */
  int class = 3;
#endif
}
