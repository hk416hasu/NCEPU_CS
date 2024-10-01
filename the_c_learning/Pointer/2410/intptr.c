#include <stdio.h>
#include <stdint.h>

int main() {

    long int num = 100;
    intptr_t* pi = &num;    // pi is a long Integer, holding the num's address
                            // u can just seems it as a normal pointer variable

    printf("%p\n", &num);
    printf("%p\n", pi);
    printf("%ld\n", *pi);

    return 0;
}
