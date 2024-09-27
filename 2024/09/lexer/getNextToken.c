#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loadFileToArray.h"

char token[100] = {0};
int tokenBufferLength = 0;

bool getNextToken(int *pos) {

    char peek = srcFile[*pos];
    
    // look-ahead(1)
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

    // Relational-operators and Assignment-operator
    if ( peek == '!' ) {
        if ( srcFile[(*pos)+1] == '=' ) {
            printf("%d %d\n", 23, 0);
            (*pos) += 2; return 0;
        } else {
            printf("%d %d\n", 9, 0);
            (*pos) += 1; return 0;
        }
    } else if ( peek == '=' ) {
        if ( srcFile[(*pos)+1] == '=' ) {
            printf("%d %d\n", 22, 0);
            (*pos) += 2; return 0;
        } else {
            printf("%d %d\n", 13, 0);
            (*pos) += 1; return 0;
        }
    } else if ( peek == '<' ) {
        if ( srcFile[(*pos)+1] == '=' ) {
            printf("%d %d\n", 19, 0);
            (*pos) += 2; return 0;
        } else {
            printf("%d %d\n", 18, 0);
            (*pos) += 1; return 0;
        }
    } else if ( peek == '>' ) {
        if ( srcFile[(*pos)+1] == '=' ) {
            printf("%d %d\n", 21, 0);
            (*pos) += 2; return 0;
        } else {
            printf("%d %d\n", 20, 0);
            (*pos) += 1; return 0;
        }
    }


    // if doesn't match any state (for test when programming)
    (*pos)++;
    return 1;
}
