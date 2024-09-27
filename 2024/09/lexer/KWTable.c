#include <stdio.h>
#include <string.h>
#include "KWTable.h"

char KWTable[KWnum][KWlength];
char EmptyItem[KWlength] = {0};

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

void checkKWTable() {
    for ( int i = 0; i < KWnum; i++ ) {
        // output until an empty item
        if ( strcmp(KWTable[i], EmptyItem) == 0 ) {
            break;
        }
        printf("%s\n", KWTable[i]);
    }
    printf("\n");
}
