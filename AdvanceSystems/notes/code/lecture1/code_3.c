#include <stdio.h>

int main() {
  int arr[4] = {1, 2, 3, 4};
  int *ptr;
  ptr = arr;
  int i = 0;

  // Normal Walk
  for (i = 0; i < 4; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  // Pointer Walk
  for (i = 0; i < 4; i++) {
    printf("%d", ptr[i]);
  }
  printf("\n");

  // Dereferencing Walk
  ptr = arr;
  for (i = 0; i < 4; i++) {
    printf("%d", *(ptr + i));
  }
  printf("\n");

  // Output: 1234
  return 0;
}
