#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int state = 0; // should be protected by mutex

void *worker_0(void *args) {
while (1) {
   pthread_mutex_lock(&mutex);

   while (!(state == 1 || state == 0 || state == 5)) {
      pthread_cond_wait(&cond, &mutex);
   }
   assert(state == 1 || state == 0 || state == 5);
   printf(">"); fflush(stdout);
   if (state == 1 ) {
      state = 2;
   } else if (state == 0) {
      state = 4;
   } else if (state == 5) {
      state = 6;
   }
   pthread_cond_broadcast(&cond);
   pthread_mutex_unlock(&mutex);
}
   return NULL;
}

void *worker_1(void *args) {
while (1) {
   pthread_mutex_lock(&mutex);

   while (!(state == 0 || state == 2 || state == 4)) {
      pthread_cond_wait(&cond, &mutex);
   }
   assert(state == 0 || state == 2 || state == 4);
   printf("<"); fflush(stdout);
   if (state == 0 ) {
      state = 1;
   } else if (state == 2) {
      state = 3;
   } else if (state == 4) {
      state = 5;
   }
   pthread_cond_broadcast(&cond);
   pthread_mutex_unlock(&mutex);
}
   return NULL;
}
void *worker_2(void *args) {
while (1) {
   pthread_mutex_lock(&mutex);

   while (!(state == 3 || state == 6)) {
      pthread_cond_wait(&cond, &mutex);
   }
   assert(state == 3 || state == 6);
   printf("_"); fflush(stdout);
   state = 0;

   pthread_cond_broadcast(&cond);
   pthread_mutex_unlock(&mutex);
}
   return NULL;
}
int main() {
   pthread_t threads[3];
   
   pthread_create(&threads[0], NULL, worker_0, NULL); // >
   pthread_create(&threads[1], NULL, worker_1, NULL); // <
   pthread_create(&threads[2], NULL, worker_2, NULL); // _

   for (int i = 0; i < 3; i++) {
      pthread_join(threads[i], NULL);
   }

   // destroy resources

   return 0;
}
