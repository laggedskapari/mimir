#include <stdio.h>
#include <stdlib.h>

int *createArray(size_t size) {
  int *ptr = malloc(sizeof(int));
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  return ptr;
}

int main() {
  int *arr = createArray(1000);
  if (arr == NULL) {
    return 1;
  }

  free(arr);
  return 0;
}
