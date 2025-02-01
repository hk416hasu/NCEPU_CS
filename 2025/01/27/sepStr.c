#include <stdio.h>
#include <string.h>

int main() {

  char arr[9] = {0};
  while (fgets(arr, sizeof(arr), stdin) != NULL) {
    if (arr[0] == '\n') {
      return 0;
    }
    if (strlen(arr) != 8) {
      for (int i = strlen(arr) - 1; i < 8; i++) {
        arr[i] = '0';
      }
    }
    if (arr[7] == '\n') {
      arr[7] = '0';
    }
    printf("%s\n", arr);
  }

  return 0;
}
