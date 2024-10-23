#include <stdio.h>
#include "set.h"

int main() {

    struct set *s1 = newSet();
    struct set *s2 = newSet();
    struct set *s3 = newSet();

    int i = 0;
    while ( i < 5 ) { addNewElemToSet(s2, i++); }
    addNewElemToSet(s2, 21);
    i = 0;
    while ( i < 10 ) { addNewElemToSet(s3, i++); }

    merge(s1, s2, s3); // s1 = s2 U s3

    return 0;
}
