#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int cpid1, cpid2, gc1_pid, gc2_pid;
  int status;
  cpid1 = fork();

  if (cpid1 == 0) {
    gc1_pid = fork();
    if (gc1_pid == 0) {
      printf("GC1 will now differenciate\n");
      char *args[] = {"ls", "-1", "/Users/0xskaper/mimir/AdvanceSystems", NULL};
      execvp("ls", args);
      exit(0);
    } else if (gc1_pid < 0) {
      perror("Fork Failed!");
      exit(1);
    } else {
      printf("C1 waiting fo GC1\n");
      waitpid(gc1_pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("GC1 Exit Status: %d\n", WEXITSTATUS(status));
      }
      if (WIFSIGNALED(status)) {
        printf(" GC1 Exit Signaled Status: %d\n", WTERMSIG(status));
      }
      exit(0);
    }
  }

  cpid2 = fork();
  if (cpid2 == 0) {
    gc2_pid = fork();
    if (gc2_pid == 0) {
      printf("GC2 will now differenciate to pwd\n");
      raise(SIGSEGV);
      char *args[] = {"pwd", NULL};
      if (chdir("/Users/0xskaper/mimir") < 0) {
        perror("Chdir failed in GC2\n");
        exit(1);
      }
      execvp("pwd", args);
      exit(0);
    } else if (gc2_pid < 0) {
      perror("fork failed!");
      exit(1);
    } else {
      printf("C2 waiting for GC2\n");
      waitpid(gc2_pid, &status, 0);

      if (WIFEXITED(status)) {
        printf("GC2 Exit Status: %d\n", WEXITSTATUS(status));
      }
      if (WIFSIGNALED(status)) {
        printf("GC2 Exit Signaled Status: %d\n", WTERMSIG(status));
      }
      exit(0);
    }
  }
  waitpid(cpid1, &status, 0);
  waitpid(cpid2, &status, 0);
  return 0;
}
