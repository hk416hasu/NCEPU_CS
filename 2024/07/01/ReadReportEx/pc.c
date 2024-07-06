#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <assert.h>

#define N 10
sem_t full, empty;

void * Produce() {
    while (1) {
        sem_wait(&empty);
        printf("(");
        sem_post(&full);
    }
}

void * Consume() {
    while(1) {
        sem_wait(&full);
        printf(")");
        sem_post(&empty);
    }
}

int main(int argc, char *argv[]) {
    assert(argc == 2);

    // 信号量初始化
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, atoi(argv[1]));

    pthread_t pArr[N];  // producer threads array
    pthread_t cArr[N];  // consumer threads array

    for (int i = 0; i < N; i++) {
        pthread_create(&pArr[i], NULL, Produce, NULL);
        pthread_create(&cArr[i], NULL, Consume, NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(pArr[i], NULL);
        pthread_join(cArr[i], NULL);
    }

    return 0;
} 