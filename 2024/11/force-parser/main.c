#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "global.h"

int main() {
    InitTokens();
    InitNTR();

    getNextToken();
    Program();

    // make sure the derivation is over
    if (strcmp(tokenBuf, tokenEmptyBuf) != 0) {
        printf("error! Tokens were NOT consumed completed\n");
    }

    CloseTokens();
    CloseNTR();

    return 0;
}