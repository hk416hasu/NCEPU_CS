#include <unistd.h>
#include <sys/syscall.h>

void _start() {
    const char msg[] = "Hello, World!\n";
    
    // Write syscall (SYS_write)
    __asm__ (
        "mov $1, %%rax\n"      // SYS_write
        "mov $1, %%rdi\n"      // File descriptor 1 (stdout)
        "mov %0, %%rsi\n"      // Address of the message
        "mov %1, %%rdx\n"      // Length of the message
        "syscall\n"
        :                      // Output operands (none)
        : "r"(msg), "r"(sizeof(msg) - 1)  // Input operands (message and length)
        : "%rax", "%rdi", "%rsi", "%rdx"  // Clobbered registers
    );
    
    // Exit syscall (SYS_exit)
    __asm__ (
        "mov $60, %%rax\n"     // SYS_exit
        "xor %%rdi, %%rdi\n"   // Exit status 0
        "syscall\n"
        :                      // No output operands
        :                      // No input operands
        : "%rax", "%rdi"       // Clobbered registers
    );
}

