#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)", getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, i am child (pid:%d)\n", getpid());
    } else {
        printf("hello, i am parent of %d (pid:%d)\n", rc, getpid());
    }
    return 0;
    // test
}