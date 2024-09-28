#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "symbolTable.h"

char STable[symbolNum][TextLength];
int  STableLength = 0;
char EmptySTitem[TextLength] = {0};

bool InitSymbolTable() {
    for ( int i = 0; i < symbolNum; i++ ) {
        memset(STable[i], 0, sizeof(char) * TextLength);
    }
    return 0;
}

/*
tokenTextID: it's the mapping ID to tokenText, range as
    variable : 1 ~ 100
    const num : 101 ~ ...
!! so the subscript will start from 1
        and the STableLength must inc at first, then add token
*/

/**
brief: is token in SymbolTable? if yes, return its tokenTextID;
    if the token is NOT in STable, return -1;
*/
int isInSTable(char *str, int len) {
    char Item[TextLength] = {0};
    strncpy(Item, str, len);
    for ( int i = 1; i < symbolNum; i++ ) {
        // if reach an EmptyItem, then break
        if ( strcmp(STable[i], EmptySTitem) == 0 ) {
            break;
        }

        // if match, then return its tokenTextID(just subscript)
        if ( strcmp(STable[i], Item) == 0 ) {
            return i;
        }
    }

    return -1;
}

/**
brief: symbolTable.add(identifier), return the tokenTextID
    if failed, return -1
*/
int STableAddToken(char *str, int len) {
    int tokenTextID_tmp = isInSTable(str, len);
    int tokenTextID = 0;
    if ( tokenTextID_tmp == -1 ) {   // token is NOT in STable
        // add this Item(token) into STable
        char Item[TextLength] = {0};
        strncpy(Item, str, len);
        if ( STableLength <= symbolNum ) {  // STable is not full
            ++STableLength;
            strcpy(STable[STableLength], Item);
            tokenTextID = STableLength;
        } else {    // failed to add new token, STable is full
            tokenTextID = -1;
        }
    } else {    // token is in STable
        tokenTextID = tokenTextID_tmp;
    }
    return tokenTextID;
}
