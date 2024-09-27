#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loadFileToArray.h"

char token[100] = {0};
int tokenBufferLength = 0;

bool getNextToken(int *pos) {

    char peek = srcFile[*pos];
    
    if ( peek ==  '+' ) {
        printf("%d %d\n", 14, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '-' ) {
        printf("%d %d\n", 15, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '*' ) {
        printf("%d %d\n", 16, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '/' ) {
        printf("%d %d\n", 17, 0);
        (*pos)++; return 0;
    } else if ( peek ==  ';' ) {
        printf("%d %d\n", 24, 0);
        (*pos)++; return 0;
    } else if ( peek ==  ',' ) {
        printf("%d %d\n", 25, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '(' ) {
        printf("%d %d\n", 26, 0);
        (*pos)++; return 0;
    } else if ( peek ==  ')' ) {
        printf("%d %d\n", 27, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '{' ) {
        printf("%d %d\n", 28, 0);
        (*pos)++; return 0;
    } else if ( peek ==  '}' ) {
        printf("%d %d\n", 29, 0);
        (*pos)++; return 0;
    }

    // if doesn't match any state (for test when programming)
    (*pos)++;
    return 1;
}
