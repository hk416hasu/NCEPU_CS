#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define bufLen 4
char tokenBuf[bufLen] = {0};
char tokenEmptyBuf[bufLen] = {0};

FILE *fp = NULL;

/**
brief: getNextToken from file and store it in tokenBuf, then return 1
    if meet the EOF, the tokenBuf will be Empty, then return 0
    */
bool getNextToken() {
    if (fgets(tokenBuf, sizeof(tokenBuf), fp) == NULL) {
        memset(tokenBuf, 0, sizeof(tokenBuf));
        return 0;
    }
    return 1;
}

bool InitTokens() {
    // use awk helping me format token.txt ( unix makes life eaiser. )
        // this should be overrided by c instead of shell
    system("awk '{ print $1 }' ./token.txt > formattedTokens");

    // open the file containing formatted tokens
    fp = fopen("./formattedTokens", "r");
        // error handle

    return 1;
}

bool CloseTokens() {
    fclose(fp);
    return 1;
}
