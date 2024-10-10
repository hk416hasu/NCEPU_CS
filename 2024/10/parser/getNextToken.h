#ifndef GETNEXTTOKEN_H
#define GETNEXTTOKEN_H

#include <stdbool.h>

extern FILE *fp;
extern char tokenBuf[];
extern char tokenEmptyBuf[];
bool getNextToken();
bool InitTokens();
bool CloseTokens();


#endif
