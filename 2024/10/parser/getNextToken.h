#ifndef GETNEXTTOKEN_H
#define GETNEXTTOKEN_H

#include <stdbool.h>

extern char tokenBuf[];
bool getNextToken();
bool InitTokens();
bool CloseTokens();


#endif
