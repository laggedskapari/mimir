#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Current User ID: %d\n", getuid());
  return 0;
}
