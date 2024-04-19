#include <stdio.h>
#include <unistd.h>

int main() {
    int grandpa = getpid();
    for (int i = 0; i < 2; i++) {
        fork(); // fork() will copy IR, so the loop_i will not be 0 always. The prograss and its children will continue form their IR(inherited), not from the beginning.
        printf("Hello, %d (parent: %d)\n", getpid()-grandpa, getppid()-grandpa);
    }
    return 0;
}