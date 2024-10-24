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
_Bool merge3Sets(set_s **s1, set_s *s2, set_s *s3, set_s *s4);

#endif
