#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

struct set* newSet() {
    struct set *p = (struct set*)malloc(sizeof(struct set));
    assert(p != NULL);
    p->len = 0;
    return p;
}

// if success, return 1; if anything wrong, return 0;
_Bool addNewElemToSet(struct set *pSet, int elem) {
    assert(pSet != NULL);
    if (pSet->len == maxSize) {
        return 0;
    }
    pSet->arr[pSet->len] = elem;
    pSet->len++;
    return 1;
}

// if elem in Set, retrun 1
_Bool isInSet(const struct set *pSet, int elem) {
    assert(pSet != NULL);
    for (int i = 0; i < pSet->len; i++) {
        if (elem == pSet->arr[i]) {
            return 1;
        }
    }
    return 0;
}

/*
brief: (new)Set1 = (Set2 U Set3)
    when success return 1;
    if anything wrong, then return 0;
*/
_Bool merge(struct set *s1, struct set *s2, struct set *s3) {
    s1 = newSet();
    assert(s2 != NULL); assert(s3 != NULL);

    for (int i = 0; i < s2->len; i++) {
        addNewElemToSet(s1, s2->arr[i]);
    }

    int elem = 0;
    for (int i = 0; i < s3->len; i++) {
        elem = s3->arr[i];
        if (!isInSet(s1, elem)) {
            addNewElemToSet(s1, elem);
        }
    }
    return 1;
}
