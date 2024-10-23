#include <stdio.h>
#include "global.h"

int main() {

    InitTokens();
    InitNTR();
    InitSTable();

    getNextToken();
    Program();
    genIR(88, 0, 0, 0);

    printIR();

    return 0;
}
