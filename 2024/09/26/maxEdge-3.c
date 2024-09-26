#include <stdio.h>
#include <stdlib.h>

int main() {
    int T = 0;  // num of tests
    scanf("%d", &T);

    int n = 0;
    long r = 0, half = 0, sum = 0;
    int count = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        half = (n >> 1);
        r = half + (n & 0x01);

        // to "optimize" multiplication with add and shift
        // (half + (n & 0x01)) * (half)
        count = 0, sum = 0;
        while ( r ) {
            if ( r & 0x01 ) {
                sum += (half << count);
            }
            count++;
            r >>= 1;
        }
        
        printf("%ld\n", sum);
    }
    return 0;
}

