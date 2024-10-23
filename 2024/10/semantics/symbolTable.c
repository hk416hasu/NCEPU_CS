#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

#define sTableMaxLen 20
#define idMaxLen 10
char* sTable[sTableMaxLen] = {0};
int sTableLen = 0;
int tempVarNum = 0;

_Bool InitSTable() {
    FILE *fp = fopen("./symbol.txt", "r");
        // error handle
    char indexBuf[3] = {0};
    int c = 0, i = 0;

    while (1) {
        if ((c = fgetc(fp)) == EOF) { break; }

        sTableLen++;
        // get index of symbol
        do {
            indexBuf[i++] = c;
        } while ((c = fgetc(fp) != 32));
        int index = atoi(indexBuf);

        // let symbol's name into sTable[index]
        sTable[index] = (char *)malloc(idMaxLen * sizeof(char));
        sTable[index] = 
            fgets(sTable[index], sizeof(sTable[index]), fp);

        // remove '\n'
        for (int m = 0; m < idMaxLen; m++) {
            if (sTable[index][m] == '\n') {
                sTable[index][m] = '\0';
            }
        }

        i = 0; c = 0; index = 0;
        indexBuf[0] = 0; indexBuf[1] = 0; indexBuf[2] = 0;
    }

    fclose(fp);
    return 1; // don't know return what
}

void printSTable() {
    for (int i = 1; i <= sTableLen; i++) {
        printf("%d %s\n", i, sTable[i]);
    }
}

int newTemp() {
    tempVarNum++;
    return (200 + tempVarNum);
}

_Bool isInSTable(char *str) {
    for (int i = 1; i <= sTableLen; i++) {
        if (!strcmp(sTable[i], str)) {
            return 1;
        }
    }
    return 0;
}
