#include <stdio.h>

int main() {
    int i = 20;
    int a = 0;
    int b = 1;
    int tmp = 0;
    while(i != 0) {
        printf("%d ", b);
        tmp = b;
        b = b + a;
        a = tmp;
        i--;
    }
    return 0;
}