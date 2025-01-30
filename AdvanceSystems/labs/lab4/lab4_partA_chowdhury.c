#include <stdio.h>
#include <stdlib.h>

int main() {
  int arrSize = 0;
  printf("Array Size: ");
  scanf("%d", &arrSize);
  int *arr = (int *)malloc(arrSize * sizeof(int));
  for (int i = 0; i < arrSize; i++) {
    printf("Enter the element %d: ", i);
    scanf("%d", arr + i);
  }
  printf("The array in reverse order is: ");
  for (int i = arrSize - 1; i >= 0; i--) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
  free(arr);
  return 0;
}
