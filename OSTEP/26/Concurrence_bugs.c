// 1.多线程取钱模拟(利用两个线程示范);
// 2.目的是展示多线程并行/并发时可能出现的错误;
// 3.本代码体现的错误是 由time-to-check 与 time-to-use不同导致的错误:
//	 最后money可能是意想不到的结果;)
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//static volatile int money = 500;
size_t money = 500;

struct ThreadArgs {
	char name;
	int want;
};

void * mythread(void * arg) {
	struct ThreadArgs * p = (struct ThreadArgs *)arg;
	printf("%c: begin, money is %d.\n", p->name, money);
	if (money >= p->want) {	// time to check
		sleep(1); // 引发OS调度, 展示并发可能的错误
		// time to use, 但是money可能已经被修改, 不满足条件了!
		money -= p->want;
	}
	printf("%c: end, money is %d.\n", p->name, money);
	return NULL;
}

int main() {
	pthread_t p1, p2;
	printf("pid: %d\n", getpid());
	printf("main: begin ( money = %d )\n", money);
	
	struct ThreadArgs arg1 = { 'A', 500 };
	struct ThreadArgs arg2 = { 'B', 300 };

	pthread_create(&p1, NULL, mythread, &arg1);
	pthread_create(&p2, NULL, mythread, &arg2);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("main: end ( money = %d )\n", money);

	fflush(stdout);
	return 0;
}	
