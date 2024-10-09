#include <stdio.h>
#include <stdlib.h>

char *token[] = { "if", "BoolExp", "StaBlock", "else", "StaBlock" };

int main() {

    int len = sizeof(token) / sizeof(token[0]);

    for ( int i = 0; i < len; i++ ) {
        printf("%s\n", token[i]);
    }

    return 0;
}
