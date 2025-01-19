#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  assert(argc == 2);

  int rc = fork(); // create a process, u can modify it before exec()
  assert(rc >= 0);

  if(rc == 0) {
    // prepare before exec()
    close(STDOUT_FILENO);
    int fd = open(argv[1], O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
    dup2(fd, 1);
    assert(fd == 1);

    // exec: load the ELF, prepare args and env... 
    // , don't forget the sentinel
    execl("/usr/bin/date", "date", (char *)0);
    // execlp("date", "date", (char *)0);
  } else {
    wait(NULL);
    write(STDOUT_FILENO, "over~\n", 6);
  }

  return 0;
}
