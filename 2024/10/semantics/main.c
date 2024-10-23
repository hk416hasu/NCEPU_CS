#include <stdio.h>
#include "global.h"

int main() {

//  InitTokens();
//  while (getNextToken()) {
//      fprintf(stdout, "%s %s", tokenBuf, tIdBuf);
//  }

//  struct set *s1 = newSet();
//  struct set *s2 = newSet();
//  struct set *s3 = newSet();

//  int i = 0;
//  while ( i < 5 ) { addNewElemToSet(s2, i++); }
//  addNewElemToSet(s2, 21);
//  i = 0;
//  while ( i < 10 ) { addNewElemToSet(s3, i++); }

//  merge(s1, s2, s3); // s1 = s2 U s3

//  printf("%d\n", s1->len);

    genIR(18, 1, 2, 7);
    genIR(30, 0, 0, 3);
    genIR(18, 1, 2, -1);
    genIR(30, 0, 0, -1);
    genIR(88, 0, 0, 0);

    struct set *s1 = newSet();
    addNewElemToSet(s1, 3);
    addNewElemToSet(s1, 4);

    backpatch(s1, 9);

    printIR();

    return 0;
}
