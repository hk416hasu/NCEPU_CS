#include <sys/syscall.h>

#define syscall3(id, a0, a1, a2) \
  mov $SYS_##id, %rax; \
  mov $a0, %rdi; \
  mov $a1, %rsi; \
  mov $a2, %rdx; \
  syscall

#define syscall2(id, a0, a1) syscall3(id, a0, a1, 0)
#define syscall1(id, a0) syscall2(id, a0, 0) // recursively syscall

.section .text
.globl _start
_start:
  syscall3(write, 1, message, (message_end - message));
  syscall1(exit, 0);

.section .data
message: .ascii "\033[01;05;31mHello World!\033[0m\n"
message_end:
