#include <stdio.h>

int min(int n1, int n2, int n3) {
  if (n1 < n2 && n1 < n3) {
    return n1;
  } else if (n2 < n1 && n2 < n3) {
    return n2;
  } else {
    return n3;
  }
}

int max(int n1, int n2, int n3) {
  if (n1 > n2 && n1 > n3) {
    return n1;
  } else if (n2 > n1 && n2 > n3) {
    return n2;
  } else {
    return n3;
  }
}

int product(int n1, int n2) { return n1 * n2; }

int compute(int (*min)(int, int, int), int (*max)(int, int, int),
            int (*product)(int, int), int n1, int n2, int n3) {
  return product(min(n1, n2, n3), max(n1, n2, n3));
}

int main() {

  int n1, n2, n3;
  printf("Enter three numbers: ");
  scanf("%d %d %d", &n1, &n2, &n3);
  printf("Result: %d\n", compute(min, max, product, n1, n2, n3));
  return 0;
}
