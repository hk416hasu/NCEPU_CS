#include <stdio.h>
#include <math.h>

#define len 10

int main() {

    for (int x = 0; x < len; x++) {
        printf("%d ", 2 * ((int)floor(x) % 2));
    }

    return 0;
}