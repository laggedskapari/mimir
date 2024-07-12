#include <stdio.h>

int getStringline(char line[]);
void copy(char to[], char from[]);

int main() {
  int max, len;
  char line[]; 
  char longest[];

  max = 0;
  while ((len = getStringline(line)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
}
