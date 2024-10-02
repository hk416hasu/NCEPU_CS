#include <stdio.h>

void func1() {
    int vector[] = {1, 2, 3};
    int* p = vector;    // vector contains the addr of the array's first elem,
                        // and p is assigned to vector, so they are equal

    printf("%p\n", p);
    printf("%p\n", vector); // so 'p' is equal to 'vector'
    printf("%d\n", *p); // output 1 (vector[0])
    printf("%d\n", *vector);

    p++;
    printf("%d\n", *p); // output vector[1]

}

void func2() {
    int vec[] = {2, 3, 4, 5, 6};
    int *p = vec;

    printf("%p\n", p);
    printf("%ld\n", sizeof(p));
    printf("%p\n", vec);
    printf("%ld\n", sizeof(vec));
    printf("%p\n", &vec[0]);
    printf("%ld\n", sizeof(&vec[0]));
    printf("%p\n", &vec);
    printf("%ld\n", sizeof(&vec));
}

void func3_sub(int (*foo)[5]) { // u need to give the length, so it's useless..
//    printf("%ld\n", sizeof(*foo)/sizeof((*foo)[0]));
//    printf("%d, %d\n", (*foo)[0], (*foo)[1]);
}

void func3() {
    int vec[] = {1, 2, 3, 4, 5};
//    printf("%ld\n", sizeof(vec)/sizeof(vec[0]));
    int (*p)[5] = &vec;
    printf("%ld\n", sizeof(*p)/sizeof((*p)[0]));
    func3_sub(p);
//    printf("%d\n", (*p)[3]);
}

int main() {
    func3();

    return 0;
}
