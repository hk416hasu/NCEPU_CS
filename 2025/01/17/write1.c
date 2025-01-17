#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <assert.h>

int main() {
  int rc = fork();
  assert(rc >= 0);
  if (rc != 0) {
    write(STDOUT_FILENO, "Hello", 5);
  } else {
    write(STDOUT_FILENO, "World", 5);
  }

  if (rc != 0) {
    wait(NULL);
    write(STDOUT_FILENO, "\n", 1);
  }

  return 0;
}
