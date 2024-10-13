#include <stdio.h>

#define len 6

int main() {
    int x[len] = { 1, 2, 3, 4, 5, 6 };
    int y[len] = { 6, 5, 4, 3, 2, 1 };
    int z[len] = {0};
    char op[len] = { '+', '-', '+', '-', '-', '+' };

    for ( int i = 0; i < len; i++ ) {
        if ( op[i] == '+' ) {
            z[i] = x[i] + y[i];
        } else {
            z[i] = x[i] - y[i];
        }
        printf("%d ", z[i]);
    }
    printf("\n");

    return 0;
}
