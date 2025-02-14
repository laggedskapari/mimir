#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig) { printf("Time\n"); }

int main() {
  int ret = alarm(10);
  printf("%d\n", ret);
  sleep(9);
  ret = alarm(3);
  printf("%d\n", ret);
  return 0;
}
