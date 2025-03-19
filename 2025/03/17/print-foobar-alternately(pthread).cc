#include <pthread.h>
#include <iostream>
#include <string>

using std::string, std::cout;

pthread_mutex_t lk = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int state = 0;

struct myclass {
   int want;
   string str;

   myclass(int x, string s) : want(x), str(s) {}
};

void* print(void *args) {
   int want = ((myclass*)args)->want;
   string str = ((myclass*)args)->str;

   for (int i = 0; i < 10; i++) {
      pthread_mutex_lock(&lk);
      while (want != state) {
         pthread_cond_wait(&cond, &lk);
      }

      cout << str;

      state = (state == 1) ? 0 : 1;
      pthread_cond_broadcast(&cond);
      pthread_mutex_unlock(&lk);
   }
   return NULL;
}

int main() {
   pthread_t t1, t2;

   struct myclass foo_arg(0, "Foo");
   struct myclass bar_arg(1, "Bar");

   pthread_create(&t1, NULL, print, &foo_arg);
   pthread_create(&t2, NULL, print, &bar_arg);

   pthread_join(t1, NULL);
   pthread_join(t2, NULL);

   cout << '\n';

   pthread_mutex_destroy(&lk);
   pthread_cond_destroy(&cond);

   return 0;
}
