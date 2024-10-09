#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

void IfSta() {
    match("if");
    match("BoolExp");
    match("StaBlock");
    match("else");
    match("StaBlock");
}

int main() {

    getNextToken();
    IfSta();

    return 0;
}
