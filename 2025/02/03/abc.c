// 3 threads looply print ABC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

#define THREADS_COUNT 3
#define LOOP_TIMES 10

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int state = 0; // this should be protected by mutex

void * worker(void *args) {
   int tid = *(int*)args;
   char ch = tid + 'A';

   for (int i = 0; i < LOOP_TIMES; i++) {
      pthread_mutex_lock(&mutex);

      while (state != tid) {
         pthread_cond_wait(&cond, &mutex);
      }
      printf("%c", ch);
      state = (state + 1) % THREADS_COUNT;
      pthread_cond_broadcast(&cond); // remember to wake them up

      pthread_mutex_unlock(&mutex);
   }

   return NULL;
}

int main() {
   pthread_t threads[THREADS_COUNT];
   int thread_args[THREADS_COUNT];

   int rc = 0;
   for (int i = 0; i < THREADS_COUNT; i++) {
      thread_args[i] = i;
      rc = pthread_create(&threads[i], NULL, worker, &thread_args[i]);
                           // u can NOT use &i here
                           // , it's a global-shared variable
      assert(rc == 0);
   }

   for (int i = 0; i < THREADS_COUNT; i++) {
      rc = pthread_join(threads[i], NULL);
      assert(rc == 0);
   }

   printf("\n");

   // free resources
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);

   return 0;
}
