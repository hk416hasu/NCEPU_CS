#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

char Empty[5] = {0};

void StaBlock();
void IfSta();
void OptElse();

int main() {

    getNextToken();
    IfSta();

    if ( strcmp(token, "EOF") != 0 ) {
        printf("error! Tokens were NOT consumed completed!\n");
    }

    return 0;
}

void StaBlock() {
    if ( !strcmp(token, "if") ) {
        IfSta();
    } else if ( !strcmp(token, "StaBlock") ) {
        match("StaBlock");
    }
    printf("StaBlock\n");
}

void OptElse(int p) {
    if ( p <= 1 ) {
        match("else");
        StaBlock();
        OptElse(2);
    }
    if ( p <= 2 ) {
        printf("OptElse\n");
        return;
    }
    // printf("OptElse\n");
}

void IfSta() {
    match("if");
    match("BoolExp");
    StaBlock();
    OptElse(0);
    printf("IfSta\n");
}
