#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define LOOP_COUNT 10  // 控制循环打印次数

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int turn = 0;  // 线程执行的顺序

void* print_char(void* arg) {
    int id = *(int*)arg;
    char ch = 'A' + id;  // 线程0打印 'A'，线程1打印 'B'，线程2打印 'C'

    for (int i = 0; i < LOOP_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        
        while (turn != id) {  // 轮到当前线程打印时才能继续
            pthread_cond_wait(&cond, &mutex);
        }

        printf("%c", ch);
        fflush(stdout);  // 立即刷新输出，避免缓存问题
        turn = (turn + 1) % NUM_THREADS;  // 切换到下一个线程

        pthread_cond_broadcast(&cond);  // 唤醒所有线程
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2};

    // 创建线程
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, print_char, &thread_ids[i]);
    }

    // 等待所有线程结束
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    // 清理资源
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

