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

// OptElse() try to match only ONCE
// if<BoolExp><StaBlock>(<OptElse>)?
void OptElse() {
    if ( !strcmp(token, "else") ) {
        match("else");
        StaBlock();
        printf("OptElse\n");
    }
}

void IfSta() {
    match("if");
    match("BoolExp");
    StaBlock();
    OptElse();
    printf("IfSta\n");
}
