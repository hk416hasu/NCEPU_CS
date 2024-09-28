#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "symbolTable.h"
#include "character.h"

char STable[symbolNum][TextLength];
int idIndex = 1;    // identifiers' index
const int ID_INDEXMAX = 101;
int numIndex = 101; // numbers' index
const int NUM_INDEXMAX = symbolNum;
// int  STableLength = 0;
char EmptySTitem[TextLength] = {0};

bool InitSymbolTable() {
    for ( int i = 0; i < symbolNum; i++ ) {
        memset(STable[i], 0, sizeof(char) * TextLength);
    }
    return 0;
}

/*
tokenTextID: it's the mapping ID to tokenText, range as
    identifier : 1 ~ 100
    const num  : 101 ~ ...
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
// BUT there're many EmptyItems between identifiers and const nums
// , so this should not work.
        //if ( strcmp(STable[i], EmptySTitem) == 0 ) {
        //    break;
        //}

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
    int tokenStatus = isInSTable(str, len);
    int tokenTextID = 0;
    if ( tokenStatus == -1 ) {   // token is NOT in STable
        // build the Token(Item)
        char Item[TextLength] = {0};
        strncpy(Item, str, len);

        if ( isLetter(Item[0]) &&           // is an identifier
                (idIndex < ID_INDEXMAX) )   // is valid
        {
            // add an identifier token
            strcpy(STable[idIndex], Item);
            tokenTextID = idIndex;
            idIndex++;
        } else if ( isDigit(Item[0]) &&     // is a number
                (numIndex < NUM_INDEXMAX) ) // is valid
        {
            // add a number token
            strcpy(STable[numIndex], Item);
            tokenTextID = numIndex;
            numIndex++;
        } else {    // failed to add new token
            tokenTextID = -1;
        }
    } else {    // token is in STable
        tokenTextID = tokenStatus;
    }
    return tokenTextID;
}

/**
brief: output all items but not EmptySTitem
    if success, return 1
    */
bool printSTable() {
    for (int i = 1; i < symbolNum; i++) {
        if ( strcmp(STable[i], EmptySTitem) != 0 ) {
            printf("%d %s\n", i, STable[i]);
        }
    }
    return 1;
}
