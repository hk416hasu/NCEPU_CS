#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <assert.h>

int main() {
  int fd = open("./foo.txt", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
  assert(fd >= 0);
  int rc = fork();
  assert(rc >= 0);
  if (rc != 0) {
    write(fd, "Hello", 5);
  } else {
    write(fd, "World", 5);
  }
  fsync(fd);
  close(fd);

  return 0;
}
