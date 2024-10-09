#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputType[] = { "if", "BoolExp", "StaBlock", "else", "StaBlock" };
int len = sizeof(inputType) / sizeof(inputType[0]);
int peek = 0;

char token[20] = {0};

_Bool getNextToken() {
    if ( peek >= len ) {
        memset(token, 0, sizeof(token));
        return 0;
    }
    strcpy(token, inputType[peek++]);
    return 1;
}

void match(char *expect) {
    if ( !strcmp(expect, token) ) {
        getNextToken();
    } else {
        printf("error in match()!\n");
        exit(1);
    }
}
