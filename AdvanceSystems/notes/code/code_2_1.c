#include <stdio.h>
#include <unistd.h>

int main() {
  printf("\nSTDIN_FILENO: %d", STDIN_FILENO);   // 0
  printf("\nSTDOUT_FILENO: %d", STDOUT_FILENO); // 1
  printf("\nSTDERR_FILENO: %d", STDERR_FILENO); // 2
};
