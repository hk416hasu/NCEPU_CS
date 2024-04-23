#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int counter = 0;

void * mythread(void * arg) {
	printf("%s: begin\n", (char *)arg);
	for (int i = 0; i < 1e7; i++) {
		// 内联汇编：直接利用原子操作对counter进行++
		asm volatile(
            "lock addq $1, %0" : "+m"(counter)
        );
	}
	printf("%s: end\n", (char *)arg);
	return NULL;
}

int main() {
	pthread_t p1, p2;
	printf("pid : %d\n", getpid());
	printf("main: begin (counter = %d)\n", counter);
	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("main: end with both (counter = %d)\n", counter);

	fflush(stdout); // 刷新标准输出流
	return 0;
}
