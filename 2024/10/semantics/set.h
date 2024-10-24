#ifndef SET_H
#define SET_H

// struct set;

#define maxSize 20
typedef struct set {
    int len;
    int arr[maxSize];
} set_s;
struct set* newSet();
_Bool addNewElemToSet(struct set *pSet, int elem);
_Bool merge(struct set **s1, struct set *s2, struct set *s3);

#endif
