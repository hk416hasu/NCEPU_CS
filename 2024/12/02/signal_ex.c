#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Signal %d received\n", sig);
    exit(0);
}

int main() {
    // signal is a function that takes an int (signal number) and a function pointer
    // signal returns a pointer to a function (like handler)
    void (*old_handler)(int) = signal(SIGINT, handler);
    
    // Now, when SIGINT (Ctrl+C) is received, handler will be called
    while(1);
    return 0;
}

