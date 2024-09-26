#include <stdio.h>

int main() {
    int T = 0;  // num of tests
    scanf("%d", &T);

    int n = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        int half = n >> 1;
        printf("%d\n", half * (half + (n & 0x01)));
    }
    return 0;
}

