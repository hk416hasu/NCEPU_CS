#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < 2; i++) {
    fork();
    printf("Hello\n");
//    fflush(stdout);
  }
  for (int i = 1; i < 2; i++) {
    wait(NULL);
  }
}
