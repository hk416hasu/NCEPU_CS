#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int is_coprime(int a, int b) {
    return gcd(a, b) == 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    int a = 0, b = 0;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if (is_coprime(a, b)) {
        printf("they are coprime\n");
    } else {
        printf("they are NOT coprime\n");
    }
    return 0;
}
