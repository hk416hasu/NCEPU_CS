#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

void getFirstColumn() {
    FILE *fb_src = fopen("./token.txt", "r");
    FILE *fb_des = fopen("./formattedTokens", "w");

    int ch = 0;
    while (1) {
        while ( ((ch = fgetc(fb_src)) != EOF) && (ch != 32) ) {
            fprintf(fb_des, "%c", ch);
        }
        while ( ((ch = fgetc(fb_src)) != EOF) && (ch != 10) );
        if ( ch == EOF ) {
            break;
        }
        fprintf(fb_des, "\n");
    }

    fclose(fb_src);
    fclose(fb_des);
}

bool InitTokens() {
    // unix makes life eaiser, but it is banned...
    // system("awk '{ print $1 }' ./token.txt > formattedTokens");

    getFirstColumn();

    // open the file containing formatted tokens
    fp = fopen("./formattedTokens", "r");
        // error handle

    return 1;
}

bool CloseTokens() {
    fclose(fp);
    return 1;
}
