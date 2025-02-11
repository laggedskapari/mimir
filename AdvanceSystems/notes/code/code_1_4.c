#include <stdio.h>
int main() {
  int a = 100;
  int *p = &a;

  printf("\nAddress of p: %p", p); // 0x16f597098
  p += 1;
  printf("\nAddress of p + 1: %p", p); // 0x16f59709c
  p -= 1;
  printf("\nAddress of p - 1: %p", p); // 0x16f597098
  p += 2;
  printf("\nAddress of p + 2: %p", p); // 0x16f5970a0
  p -= 2;
  printf("\nAddress of p - 2: %p\n", p); // 0x16f597098
  return 0;
}
