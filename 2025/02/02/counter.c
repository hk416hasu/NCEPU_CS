#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static volatile int counter = 0;
#define LOOPTIMES (int)10e7

void* mythread(void *args) {
   for (int i = 0; i < LOOPTIMES; i++) {
//    counter = counter + 1;
      __asm__ (
            "incq %0\n"
//          "lock addq $1, %0\n"
            : "=m"(counter)
            );
   }
}


int main() {
   pthread_t t1, t2;

   pthread_create(&t1, NULL, mythread, NULL);
   pthread_create(&t2, NULL, mythread, NULL);

   pthread_join(t1, NULL);
   pthread_join(t2, NULL);

   printf("Expected rusult: %d\n", 2 * LOOPTIMES);
   printf("The Read result: %d\n", counter);
   return 0;
}

