#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>

void Handler(int signo) { printf("\nIn the handler\n"); }

int main(int argc, char *argv[]) {

  signal(SIGALRM, Handler); // install the handler

  alarm(5);

  printf("Pausing\n");

  int i = pause();

  printf("Resuming\n");

  printf("The return value of pause(): %d\n",
         i); // if handler -1 else never returns
}
