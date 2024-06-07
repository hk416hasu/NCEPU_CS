#include <stdio.h>

#define num 0xFFFFFFFF

int main() {

    unsigned b = num;
    int a = *((int *)&b);

    return 0;
}