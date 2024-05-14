// 1.多线程取钱模拟(利用两个线程示范);
// 2.目的是展示并发时可能出现的错误;
// 3.本代码体现的错误是 由time-to-check 与 time-to-use不同导致的错误:
//	 最后共享变量money可能是意想不到的结果:)
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int money = 500;	// 账户里有500元

struct ThreadArgs {
	char name;  // 取钱人
	int want;  // 想取 want 元
};

void * getMoney(void * arg) {
	struct ThreadArgs *p = (struct ThreadArgs *)arg;
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
	printf("main: begin ( money = %d )\n", money);	// 输出起始的钱数
	
	struct ThreadArgs arg1 = { 'A', 500 };  // A 想取 500 元
	struct ThreadArgs arg2 = { 'B', 300 };  // B 想取 300 元

	pthread_create(&p1, NULL, getMoney, &arg1); // 创建线程 1 : A取钱
	pthread_create(&p2, NULL, getMoney, &arg2); // 创建线程 2 : B取钱

	pthread_join(p1, NULL); // 等待线程 1 结束
	pthread_join(p2, NULL); // 等待线程 2 结束

	printf("main: end ( money = %d )\n", money);	// 输出剩余的钱数

	fflush(stdout);
	return 0;
}	
