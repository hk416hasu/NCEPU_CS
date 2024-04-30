#include <stdio.h>

int main() {

    double k = 0.0;
    scanf("%lf", &k);
    double x = 0.0, y = 0.0;
    for (y = k+1; y <= 2*k; y++) {
        x = (k * y) / (y - k);
        if ((int)(x) == x) {
            printf("1/%d = 1/%d + 1/%d\n", (int)k, (int)x, (int)y);
        }
    }

    return 0;
}