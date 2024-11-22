#include <stdio.h>

int main() {
    char *m1 = "hello\n";
    printf("%d\n", (int)sizeof(m1)); // 8, just the pointer size

    char m2[100] = "hello\n";
    printf("%d\n", (int)sizeof(m2)); // 100

    return 0;
}
