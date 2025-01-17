#include <stdio.h>

void *func(void *) {
  printf("hello world\n");
}

void ex_layer(void *(*routine)(void *)) {
  (*routine)(NULL);
}

int main(void) {
  ex_layer(func);
  return 0;
}

