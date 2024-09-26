#include <stdio.h>
#include "loadFileToArray.h"

int main() {

    loadFileToArray();

    for ( int i = 0; i < srcFileBufferLength; i++) {
        printf("%c", srcFileBuffer[i]);
    }
    printf("\n");
}
