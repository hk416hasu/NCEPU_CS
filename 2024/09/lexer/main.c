#include <stdio.h>
#include "global.h"

int main() {

    InitSymbolTable();

    FILE *fp = NULL;
    InitTokenOutputFile(&fp);

    // const char *fileName = "./source.txt";
    loadFileToArray();

    int pos = 0;    // each time, start to get token from pos
    while ( pos < srcFileLength && srcFile[pos] != 0 ) {
        // pos will be updated in getNextToken()
        // tokens will also be output in it
        getNextToken(&pos, fp);
    }

    fclose(fp);

    // print symbols to symbol.txt
    printSTable();

    return 0;
}
