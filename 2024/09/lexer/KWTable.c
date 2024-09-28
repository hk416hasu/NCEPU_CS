#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "KWTable.h"

char KWTable[KWnum][KWlength];
char EmptyKW[KWlength] = {0};

bool InitKWTable() {
    for ( int i = 0; i < KWnum; i++ ) {
        memset(KWTable[i], 0, sizeof(char) * KWlength);
    }

    strcpy(KWTable[0], "main");
    strcpy(KWTable[1], "int");
    strcpy(KWTable[2], "float");
    strcpy(KWTable[3], "if");
    strcpy(KWTable[4], "else");
    strcpy(KWTable[5], "while");
    //strcpy(KWTable[6], "main");
    //strcpy(KWTable[7], "main");
    //strcpy(KWTable[8], "main");
    //strcpy(KWTable[9], "main");
    //strcpy(KWTable[10], "main");

    return 1;
}

bool isInKWTable(char *str, int len) {
    char Item[KWlength] = {0};
    strncpy(Item, str, len);
    for ( int i = 0; i < KWnum; i++ ) {
        // if reach an EmptyKW, then break
        if ( strcmp(KWTable[i], EmptyKW) == 0 ) {
            break;
        }

        // if match, return success
        if ( strcmp(KWTable[i], Item) == 0 ) {
            return 1;
        }
    }
    return 0;
}

int getKWtokenType(char *str, int len) {
    char Item[KWlength] = {0};
    strncpy(Item, str, len);

    if ( !strcmp(Item, "main") ) {
        return 1;
    } else if ( !strcmp(Item, "int") ) {
        return 2;
    } else if ( !strcmp(Item, "float") ) {
        return 3;
    } else if ( !strcmp(Item, "if") ) {
        return 4;
    } else if ( !strcmp(Item, "else") ) {
        return 5;
    } else if ( !strcmp(Item, "while") ) {
        return 6;
    }

    return -1;
}

void checkKWTable() {
    for ( int i = 0; i < KWnum; i++ ) {
        // output until an empty item
        if ( strcmp(KWTable[i], EmptyKW) == 0 ) {
            break;
        }
        printf("%s\n", KWTable[i]);
    }
    printf("\n");
}
