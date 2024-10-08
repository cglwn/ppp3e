// C++ has four different notations for initialization. Some disallow narrowing.
int main() {
  int x0 = 7.8;
#if false
  // These ones prevent narrowing and are preferred for more complex initialization.
  int x1{7.8}; // error: {} doesn't narrow
  int x2 = {7.8}; // error: ={} doesn't narrow
#endif
  int x3(7.8);
}
