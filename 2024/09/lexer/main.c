#include <stdio.h>
#include "loadFileToArray.h"
#include "getNextToken.h"

int main() {

    // const char *fileName = "./source.txt";
    loadFileToArray();

    int pos = 0;    // each time, start to get token from pos
    while ( pos < srcFileLength && srcFile[pos] != 0 ) {

        // pos will be updated in getNextToken()
        getNextToken(&pos);

        // print token to somewhere

    }

    return 0;
}
