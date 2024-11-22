#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int pid = fork();

    if (pid < 0) {
        perror("error in fork()\n");
    } else if (pid == 0) {
        printf("i am the child process: %d\n", (int)getpid());
        while(1);
    } else {
        wait(0); // wait for the return of any child process
        printf("i am his father: %d\n", (int)getpid());
    }

    return 0;
}
