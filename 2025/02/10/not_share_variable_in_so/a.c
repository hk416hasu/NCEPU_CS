#include <stdio.h>
#include <unistd.h>

extern int global_Value;

int main() {
   while (1) {
      printf("%d\n", global_Value++);
      sleep(1);
   }
}
