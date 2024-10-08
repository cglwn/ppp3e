int area(int length, int width) {
  return length * width;
}

int main() {
#if false
  int x0 = arena(7,2); // error : undeclared function
  int x1 = area(7); // error : wrong number of arguments
  int x2 = area("seven",2); // error : 1st argument has a wrong type
#endif
  // Not all type errors are caught by the compiler.
  int x4 = area(10,-7); // OK: but what is a rectangle with a width of minus 7?
  int x5 = area(10.7,9.3); // OK: but calls area(10,9)
  char x6 = area(100,9999); // OK: but truncates the result
}
