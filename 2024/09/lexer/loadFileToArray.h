#ifndef LOADFILETOARRAY_H
#define LOADFILETOARRAY_H

#include <stdbool.h>

bool isWhiteSpace(int ch);
bool loadFileToArray();
extern int srcFileBufferLength;
extern int srcFileBuffer[2000];

#endif
