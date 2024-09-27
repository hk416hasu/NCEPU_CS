#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "symbolTable.h"

char symbolTable[symbolNum][TextLength];

bool InitSymbolTable() {
    for ( int i = 0; i < symbolNum; i++ ) {
        memset(symbolTable[i], 0, sizeof(char) * TextLength);
    }
    return 0;
}

bool isInSTable(char *str, int len) {

    return 1;
}

/**
    brief: symbolTable.add(identifier), return the tokenTextID
    */
int STableAddId(char *str, int len) {

    // variable : 1 ~ 100
    // const num : 101 ~ ...
    int tokenTextID = 1;

    return tokenTextID;
}
