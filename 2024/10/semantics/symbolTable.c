#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

#define sTableMaxLen 300
#define idMaxLen 10
#define indexBufLen 4
char* sTable[sTableMaxLen] = {0};
int tempVarNum = 0;

_Bool InitSTable() {
    FILE *fp = fopen("./symbol.txt", "r");
        // error handle
    char indexBuf[indexBufLen] = {0};
    int c = 0, i = 0;

    while (1) {
        if ((c = fgetc(fp)) == EOF) { break; }

        // get index of symbol
        do {
            indexBuf[i++] = c;
        } while ((c = fgetc(fp)) != 32);
        int index = atoi(indexBuf);

        // let symbol's name into sTable[index]
        sTable[index] = (char *)malloc(idMaxLen * sizeof(char));
        sTable[index] = 
            fgets(sTable[index], sizeof(sTable[index]), fp);

        i = 0; c = '\0'; index = 0;
        memset(indexBuf, 0, sizeof(char)*indexBufLen);
    }

    fclose(fp);
    return 1; // don't know return what
}

void printSTable() {
    for (int i = 1; i < sTableMaxLen; i++) {
        if (sTable[i] != NULL) {
            printf("%d %s", i, sTable[i]);
        }
    }
}

int newTemp() {
    tempVarNum++;
    return (200 + tempVarNum);
}

_Bool isInSTable(int index) {
    return (sTable[index] != NULL);
}
