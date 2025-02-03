#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int main() {
   pid_t pid = fork();
   assert(pid >= 0);
   if (pid == 0) {
      close(STDOUT_FILENO);
      int ret = printf("hello world\n");
      assert(ret >= 0);
   }
   return 0;
}
