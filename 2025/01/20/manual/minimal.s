# GCC use AT&T format of assembly

.section .text
.globl _start # global identifier
_start:
  mov $1, %rax
  mov $1, %rdi
  # mov $message, %rsi
  lea message, %rsi
  # mov $6, %rdx
  mov $(message_end - message), %rdx
  syscall

loop:
  jmp loop
# pmap $(pidof minimal)

  mov $60, %rax; mov $0, %rdi; syscall

.section .data
message: .ascii "\033[01;05;31mHello World!\033[0m\n"
message_end:

/* vim: ft=gas :
*/
