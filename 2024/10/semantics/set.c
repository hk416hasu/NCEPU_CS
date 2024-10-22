#include <stdio.h>

#define maxSize 20

struct set {
    int len;
    int arr[maxSize];
};

// if success, return 1; if anything wrong, return 0;
_Bool addNewElemToSet(struct set *pSet, int elem) {
    if (pSet->len == maxSize) {
        return 0;
    }
    pSet->arr[pSet->len] = elem;
    pSet->len++;
    return 1;
}

// if elem in Set, retrun 1
_Bool isInSet(const struct set *pSet, int elem) {
    for (int i = 0; i < pSet->len; i++) {
        if (elem == pSet->arr[i]) {
            return 1;
        }
    }
    return 0;
}

/*
brief: Set1 = (Set2 U Set3)
    when success return 1;
    if anything wrong, then return 0;
*/
_Bool merge(struct set *s1, struct set *s2, struct set *s3) {
    s1->len = 0;

    for (int i = 0; i < s2->len; i++) {
        addNewElemToSet(s1, s2->arr[i]);
    }

    int elem = 0;
    for (int i = 0; i < s3->len; i++) {
        elem = s3->arr[i];
        if (!isInSet(s1, elem)) {
            return addNewElemToSet(s1, elem);
        }
    }
}

int main() {

    struct set s1; s1.len = 0; // do NOT forget to initialize!!!
    struct set s2; s2.len = 0; // do NOT forget to initialize!!!
    struct set s3; s3.len = 0; // do NOT forget to initialize!!!

    int i = 0;
    while ( i < 5 ) { addNewElemToSet(&s2, i++); }
    i = 0;
    while ( i < 10 ) { addNewElemToSet(&s3, i++); }

    merge(&s1, &s2, &s3); // s1 = s2 U s3

    return 0;
}
