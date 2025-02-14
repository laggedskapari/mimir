#include <stdio.h>

int main() {
  void *ptr;
  int a = 200;
  ptr = &a;
  int *b;
  b = ptr;
  printf("%d\n", *b);

  float c = 10.83;
  ptr = &c;
  float *g;
  g = ptr;
  printf("%d\n", *b);
}
