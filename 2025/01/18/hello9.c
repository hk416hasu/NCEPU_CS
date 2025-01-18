#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

int main() {
  // 0: 邪教
  system("echo hello world from system");

  // 1: 正常
  puts("hello world from puts");
  fputs("hello world form fputs\n", stdout);
  printf("hello world from printf\n");
  fprintf(stdout, "hello world from fprintf\n"); // format
  fwrite("hello world from fwrite\n", sizeof(char), 24, stdout); // no format, just print

  // 2: 略显奇怪
  write(STDOUT_FILENO, "hello world from write in unistd.h\n", 35);
  syscall(SYS_write, STDOUT_FILENO, "hello world from syscall directly\n", 34);

  // 3: 邪教
  __asm__ (
      "mov $1, %%rdi\n"
      "mov %0, %%rsi\n"
      "mov %1, %%rdx\n"
      "mov $1, %%rax\n"
      "syscall"
      :
      : "r"("hello world from asm\n"), "i"(21)
      );

  return 0;
}
