#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isWhiteSpace(int ch) {
    if ( ch == ' ' || ch == '\n' || ch == '\t' \
            || ch == '\r' || ch == '\f' || ch == '\v' )
    {
        return 1;
    }
    return 0;
}

int srcFileBufferLength = 0;
int srcFileBuffer[10000] = {0};

/**
  @brief: load src file to an array, and filter all WhiteSpace
  */
bool loadFileToArray() {
    // open a file: get its file describer or pointer
    FILE *srcFD = fopen("./source.txt", "r"); // file describer
    if ( srcFD == NULL ) {
        perror("failed to open file");
        return 0;
    }

    // get that file's content and put it into array(buffer)
    int i = 0;
    int ch = 0; // note: int, not char, required to handle EOF
    while ( (ch = fgetc(srcFD)) != EOF ) {
        if ( isWhiteSpace(ch) ) {
            continue;   // skip whitespace
        }
        srcFileBuffer[i++] = ch;
    }
    srcFileBufferLength = i;

    return 1;
}
