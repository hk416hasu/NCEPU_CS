#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  assert(argc == 3);

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  int r = -1;
  while (1) {
    r = m % n;
    if (r == 0) {
      break;
    }
    m = n;
    n = r;
  }

  printf("the gcd is %d\n", n);

  return 0;
}
