#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char tokenBuf[4] = {0};

FILE *fp = NULL;

// if not meet EOF, update buf and return 1
bool getNextToken() {
    if (fgets(tokenBuf, sizeof(tokenBuf), fp) == NULL) {
        memset(tokenBuf, '0', sizeof(tokenBuf));
        return 0;
    }
    return 1;
}

bool InitTokens() {
    // use awk helping me format token.txt ( unix makes life eaiser. )
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
