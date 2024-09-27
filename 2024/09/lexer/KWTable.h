#ifndef KWTABLE_H
#define KWTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define KWnum       100
#define KWlength    10

extern char KWTable[KWnum][KWlength];
extern char EmptyItem[KWlength];
bool InitKWTable();
bool isInKWTable(char *str, int len);
int getKWtokenType(char *str, int len);
void checkKWTable();

#endif

