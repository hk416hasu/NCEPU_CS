#include <stdio.h>
#include <string.h>

int main() {

  char arr[10] = {'h', 'e', 'l', 'l', 'o', '\n' , '\0'};
  printf("%ld\n", strlen(arr));
  return 0;
}

