#ifndef IR_H
#define IR_H

#include "set.h"

_Bool backpatch(struct set *s, int M); // goto the addr "M"
void printIR();
void genIR();
int getPC();

#endif
