#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TextLength  30
#define symbolNum   500

extern char symbolTable[symbolNum][TextLength];
bool InitSymbolTable();


#endif
