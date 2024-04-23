#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

static volatile int counter = 0;
pthread_mutex_t lock; // 定义一把全局互斥锁

void * mythread(void * arg) {
	printf("%s: begin\n", (char *)arg);
	for (int i = 0; i < 1e7; i++) {
		// 进入临界区前要先取锁
		pthread_mutex_lock(&lock);	// ..._lock()里用的是原子指令(比如atomic_xchg), 以保证线程并发安全
		// 进入临界区
		counter = counter + 1;
		//释放锁
		pthread_mutex_unlock(&lock);
	}
	printf("%s: end\n", (char *)arg);
	return NULL;
}

int main() {
	pthread_t p1, p2;
	printf("pid : %d\n", getpid());
	printf("main: begin (counter = %d)\n", counter);

	// 初始化锁(动态)
	int rc = pthread_mutex_init(&lock, NULL);
	assert(rc == 0);

	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("main: end with both (counter = %d)\n", counter);

	pthread_mutex_destroy(&lock);	// 销毁锁

	fflush(stdout); // 刷新标准输出流
	return 0;
}
