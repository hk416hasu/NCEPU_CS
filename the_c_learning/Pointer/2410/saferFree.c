#include <stdio.h>
#include <stdlib.h>

#define safeFree(p) saferFree((void**)&(p))

void saferFree(void **pp) {
    if ( pp != NULL && *pp != NULL ) {
        free((*pp));
        *pp = NULL;
    }
}

int main() {

    // int *p = NULL;
    // void *ptr = malloc(sizeof(int));
    // p = (int *)ptr;

    int *p = (int *)malloc(sizeof(int));
    *p = 5;
    safeFree(p);
    safeFree(p);

    return 0;
}
