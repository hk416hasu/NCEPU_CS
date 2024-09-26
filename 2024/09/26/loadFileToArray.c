#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isWhiteSpace(int ch) {
    if ( ch == ' ' || ch == '\n' || ch == '\t' \
            || ch == '\r')
    {
        return 1;
    }
    return 0;
}

int srcFileBufferLength = 0;

int main() {
    // open a file: get its file describer or pointer
    FILE *srcFD = fopen("./source.txt", "r"); // file describer
    if ( srcFD == NULL ) {
        perror("failed to open file");
        return 1;
    }

    int srcFileBuffer[2000] = {0};

    // get that file's content
    //  and put it in array
    int i = 0;
    int ch = 0; // note: int, not char, required to handle EOF
    while ( (ch = fgetc(srcFD)) != EOF ) {
        if ( isWhiteSpace(ch) ) {
            continue;
        }
        srcFileBuffer[i++] = ch;
    }
    srcFileBufferLength = i;

    return 0;
}
