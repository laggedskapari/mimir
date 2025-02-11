#include <stdio.h>

int main(void) {
  int num = 100;
  int *b;

  b = &num;
  printf("*b: %d\n", *b); // 100

  int **c;
  c = &b;
  printf("**c: %d\n", **c); // 100

  int ***d;
  d = &c;
  printf("***d: %d\n", ***d); // 100
}
