#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>

void CtrHandler(int signum) { printf("%d is pressed\n", signum); }

int main(int argc, char *argv[]) {
  void (*oldHandler1)(); // to save default handlers for CTR-C and CTR-Z
  void (*oldHandler2)(); // to save default handlers for CTR-C and CTR-Z
  void (*newHandler1)(); // to save new handlers for CTR-C and CTR-Z
  void (*newHandler2)(); // to save new handlers for CTR-C and CTR-Z

  oldHandler1 = signal(SIGINT, CtrHandler);  // CTR-C
  oldHandler2 = signal(SIGTSTP, CtrHandler); // CTR-Z

  for (int i = 1; i <= 10; i++) {
    printf("I am not sensitive to CTR-C/CTR-Z\n");
    sleep(1);
  }

  newHandler1 = signal(SIGINT, oldHandler1);  // restore default
  newHandler2 = signal(SIGTSTP, oldHandler2); // restore default

  for (int i = 1; i <= 10; i++) {
    printf("I am sensitive to CTR-C/CTR-Z\n");
    sleep(1);
  }

  oldHandler1 = signal(SIGINT, newHandler1);  // ignore CTR-C
  oldHandler2 = signal(SIGTSTP, newHandler2); // ignore CTR-Z

  for (int i = 1; i <= 10; i++) {
    printf("I am not sensitive to CTR-C/CTR-Z\n");
    sleep(1);
  }
}
