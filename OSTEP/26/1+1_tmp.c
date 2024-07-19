#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int counter = 0;

void * mythread(void * arg) {
	for (int i = 0; i < 1e9; i++) {
        
//        counter += 1;

//        counter++;

//        ++counter;
        
/*
        int tmp = counter;
        asm volatile(
            "incq %0" : "+m"(tmp)
        );
        counter = tmp; 
*/		
    
        // 内联汇编：直接利用原子操作对counter进行操作; "+m"表示读写memory操作数
		asm volatile(
            "lock addq $1, %0" : "+m"(counter)	// 原子 += 1
//            "addq $1, %0" : "+m"(counter)	// 非原子 += 1
//            "incq %0" : "+m"(counter)   // counter++        
        );

//        usleep(1);

	}
	return NULL;
}

int main() {
	pthread_t p1, p2;
	printf("main: begin ( counter = %d )\n", counter);
	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("main: end with both ( counter = %d )\n", counter);

	fflush(stdout); // 刷新标准输出流
	return 0;
}
