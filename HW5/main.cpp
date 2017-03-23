#include "Matrix.h"

int main() {
  Matrix m(2,2);
  m.set(0,0,4);
  // m.print();
  Matrix n(2,2);
  n.set(0,0,1);
  Matrix b = m * n;
  b.print();
  return 0;
}
