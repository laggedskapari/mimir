#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

// Return value and other features of the alarm() system call

int main(int argc, char *argv[]) {

  alarm(6);
  int ret = alarm(4); // ret = 6
  printf("alarm() is: %d ", ret);

  while (1) {
    printf("sec\n");
    sleep(1);
  }

  printf("Exiting on Alarm\n");
  exit(0);
}
