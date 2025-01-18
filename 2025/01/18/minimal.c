// gcc -nostdlib ./minimal.c
void _start(void) {
  __asm__ (
      "mov $1, %%rdi\n"
      "mov %0, %%rsi\n"
      "mov %1, %%rdx\n"
      "mov $1, %%rax\n"
      "syscall"
      :
      : "r"("Hello World!\n"), "i"(13)
      );
  __asm__ (
      "mov $0, %%rdi\n"
      "mov $60, %%rax\n"
      "syscall"
      :
      :
      );
}
