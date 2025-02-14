#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i = fork();

  if (i == 0) {
    printf("This is Child\n");
    printf("i: %d\n", i);
    exit(0);
  } else if (i < 0) {
    printf("Failed!\n");
  } else {
    printf("This is Parent\n");
    printf("i: %d\n", i);
    sleep(10);
  }

  return 0;
}
