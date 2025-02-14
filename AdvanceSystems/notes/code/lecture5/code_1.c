#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int a = alarm(4); // a = 0
  printf("a: %d\n", a);

  int b = alarm(10); // b = 4
  printf("b: %d\n", b);

  while (1) {
    printf("Sec\n");
    sleep(1);
  }
  printf("Exiting on Alarm\n");
  exit(0);
}
