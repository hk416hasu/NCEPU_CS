#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    puts("");
    printf("Signal %d received, ", sig);
    printf("but i do NOT want to exit :3\n");
}

int main(void) {
    signal(SIGQUIT, handler);
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    signal(SIGTERM, handler);
    signal(SIGSTOP, handler);

    while (1);

    return 0;
}

// kill -SEGV $(pgrep process-name)

// where is SIGINT defined?
// /usr/include/x86_64-linux-gnu/asm/signal.h
