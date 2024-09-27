#ifndef GETNEXTTOKEN_H
#define GETNEXTTOKEN_H

#include <stdbool.h>

bool getNextToken(int *pos);
extern char tokenBuffer[];
extern int tokenLength;

#endif
