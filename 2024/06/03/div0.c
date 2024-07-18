#include <stdio.h>

int main() {

    double a = 0.0;
    double b = 1.0;
    double c = b/a;

    long long i = *( long long *) &c;

    printf("%lf\n", c);

    while (1);

    return 0;
}
