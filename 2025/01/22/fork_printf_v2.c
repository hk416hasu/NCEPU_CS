#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  fork();
  printf("Hello\n");
  fork();
  printf("World\n");
  wait(NULL);
  return 0;
}
