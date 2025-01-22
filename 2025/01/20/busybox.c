#include <unistd.h>

int main() {
  execl("/usr/bin/busybox", "ls", "--color=always" ,NULL);
}
