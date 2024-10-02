#include <stdio.h>
#include <stdlib.h>

void key(int times) {
    for (int i = 0; i < times; i++) {
        printf("42\n");
    }
}

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        perror("error args");
        exit(1);
    }
    int num = atoi(argv[1]);

    void (*foo)(int) = &key;    // pointer foo is pointing to key()
    // void (*foo)(int) = key;  // same as &key
    //(*foo)(num);  // function key invoked through the function designator
    foo(num);       // function key invoked directly through the pointer

    // Unlike functions, pointers to functions are objects and 
    // thus can be stored in arrays, copied, assigned, 
    // passed to other functions as arguments, etc. 

    return 0;
}
