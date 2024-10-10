#include <stdio.h>
#include <stdbool.h>

int main() {
    if ( 0.1 ) {
        printf("hello 0.1\n");
    }
    if ( 1 ) {
        printf("hello 1\n");
    }
    if ( 0.0 ) {
        printf("hello 0.0\n");
    }
    if ( 0 ) {
        printf("hello 0\n");
    }
    if ( 0.0 || 0.1 ) {
        printf("hello 0.0 || 0.1\n");
    }
    return 0;
}
