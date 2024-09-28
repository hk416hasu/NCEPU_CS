#ifndef GETNEXTTOKEN_H
#define GETNEXTTOKEN_H

#include <stdbool.h>

bool getNextToken(int *pos, FILE *fp);
bool InitTokenOutputFile();
extern char tokenBuffer[];
extern int tokenLength;

#endif
