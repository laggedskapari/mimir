#include <stdio.h>
int main() {
  int ar[100];
  int *p1, *p2;

  p1 = ar;
  p2 = &ar[60];
  printf("p2 - p1 (offset): %ld\n", p2 - p1); // 60

  p1 = &ar[30];
  p2 = &ar[100];
  printf("p2 - p1 (offset): %ld\n", p2 - p1); // 70
  printf("p1 - p2 (offset): %ld\n", p1 - p2); // -70
  return 0;
}
