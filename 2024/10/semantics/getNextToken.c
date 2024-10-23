#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bufLen 4
char tokenBuf[bufLen] = {0};
char tIdBuf[bufLen] = {0}; // tokenTextId buffer
char tokenEmptyBuf[bufLen] = {0};

FILE *fp = NULL;

/**
brief: getNextToken from file and store in bufs, then return 1
    if meet the EOF, the Bufs will be Empty, then return 0
    */
_Bool getNextToken() {
    memset(tokenBuf, 0, sizeof(tokenBuf));
    memset(tIdBuf, 0, sizeof(tIdBuf));
    int c = 0, i = 0;
    if ((c = fgetc(fp)) == EOF) { return 0; }

    do {
        tokenBuf[i++] = c;
    } while ((c = fgetc(fp)) != 32);
    fgets(tIdBuf, sizeof(tIdBuf), fp);

    return 1;
}

_Bool InitTokens() {
    fp = fopen("./token.txt", "r");
        // error handle
    return 1;
}

_Bool CloseTokens() {
    fclose(fp);
    return 1;
}
