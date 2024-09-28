#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loadFileToArray.h"
#include "character.h"

int srcFileLength = 0;
int srcFile[10000] = {0};

/**
  @brief: load src file to an array, and filter multi-Space
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
    int old_ch = 0;
    while ( (ch = fgetc(srcFD)) != EOF ) {
        if ( isWhiteButNotSpace(ch) ) {
            continue;   // skip those White char BUT NOT Space
        }
        // remove multi-Space
        if ( old_ch != ' ' || ch != ' ' ) {
            srcFile[i++] = ch;
        }
        old_ch = ch;
    }
    srcFileLength = i;

    return 1;
}
