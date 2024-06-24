#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define n 24

static volatile unsigned long long counter = 0; 

void * myroutine(void * arg) {
    while (1) {
        asm volatile (
            "lock addq $1, %0" : "+m"(counter)
        );
    }
}

int main() {

    pthread_t arr[n];

    for (int i = 0; i < n; i++)
        pthread_create(&arr[i], NULL, myroutine, NULL);

    for (int i = 0; i < n; i++)
        pthread_join(arr[i], NULL);

	return 0;
}
