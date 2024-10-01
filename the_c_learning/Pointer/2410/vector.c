#include <stdio.h>

int main() {
    int vector[] = {1, 2, 3};
    int* p = vector;    // vector contains the addr of the array's first elem,
                        // and p is assigned to vector, so they are equal

    printf("%p\n", p);
    printf("%p\n", vector); // so 'p' is equal to 'vector'
    printf("%d\n", *p); // output 1 (vector[0])
    printf("%d\n", *vector);

    p++;
    printf("%d\n", *p); // output vector[1]

    return 0;
}
