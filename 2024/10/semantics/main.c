#include <stdio.h>
#include "global.h"

int main() {

    InitTokens();
    InitNTR();
    InitSTable();

    Program();

    printIR();

    return 0;
}
