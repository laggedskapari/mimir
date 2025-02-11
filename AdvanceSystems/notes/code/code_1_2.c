#include <stdio.h>

int main() {
  int n1 = 10, n2;
  int *ptr;

  ptr = &n1;
  n2 = *ptr;
  printf("n1: %d  n2: %d  *ptr: %d\n", n1, n2,
         *ptr); // n1: 10  n2: 10  *ptr: 10
  return 0;
}
