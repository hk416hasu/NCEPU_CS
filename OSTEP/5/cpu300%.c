#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * myroutine(void * arg) {
    while (1) {
        printf("%s", (char *)arg);   
    }
}

int main() {
    pthread_t p0,p1,p2;
    pthread_create(&p0, NULL, myroutine, "A");
    pthread_create(&p1, NULL, myroutine, "B");
    pthread_create(&p2, NULL, myroutine, "C");

    pthread_join(p0, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}
