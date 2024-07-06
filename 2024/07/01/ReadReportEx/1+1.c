#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define N 10
#define Step 1e7

static volatile int counter = 0;
pthread_mutex_t lock; // 定义一把全局互斥锁

void * mythread(void * arg) {
    // 对counter累加
	for (int i = 0; i < Step; i++) {
		// 进入临界区前要先取锁
		// pthread_mutex_lock(&lock);
		// 进入临界区
		counter = counter + 1;
		// 释放锁
		// pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main() {
	pthread_t tArr[N];  // threads array
	printf("begin:  counter  =  %d\n", counter);

	// 初始化锁(动态)
	int rc = pthread_mutex_init(&lock, NULL);
	assert(rc == 0); // 加入断言, 确保正确初始化

    // 创建线程们, 均执行mythread()
    for (int i = 0; i < N; i++) {
        pthread_create(&tArr[i], NULL, mythread, NULL);
    }
	
    // 等待线程们结束
    for (int i = 0; i < N; i++) {
        pthread_join(tArr[i], NULL);
    }

	printf("end:    counter  =  %d\n", counter);
    printf("counter should be : %d\n", N * (int)Step);

	pthread_mutex_destroy(&lock);	// 销毁锁

	return 0;
}
