#include <stdio.h>
#include "global.h"

int main() {

    InitKWTable();
    InitSymbolTable();
    InitTokenOutputFile();

    // const char *fileName = "./source.txt";
    loadFileToArray();

    FILE *fp = fopen("./token.txt", "a");
    if ( fp == NULL ) {
        perror("failed to open token.txt");
        return 1;
    }

    int pos = 0;    // each time, start to get token from pos
    while ( pos < srcFileLength && srcFile[pos] != 0 ) {

        // pos will be updated in getNextToken()
        getNextToken(&pos, fp);

        // print token to somewhere

    }
    fclose(fp);

    printSTable();

    return 0;
}
