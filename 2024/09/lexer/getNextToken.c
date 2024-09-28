#include "global.h"

char tokenBuffer[100] = {0};
int tokenLength = 0;

void step(int *pos) {
    (*pos)++;
}

bool isLetter(char ch);
bool isDigit(char ch);
bool isLetterOrDigit(char ch);

bool ID(int *pos);
bool NUMBER(int *pos);

void printTokenBufferForTest();

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

    // Logical-operators
    if ( peek == '|' ) {
        if ( srcFile[(*pos)+1] == '|' ) {
            printf("%d %d\n", 7, 0);
            (*pos) += 2; return 0;
        }
    } else if ( peek == '&' ) {
        if ( srcFile[(*pos)+1] == '&' ) {
            printf("%d %d\n", 8, 0);
            (*pos) += 2; return 0;
        }
    }

    // Identifier and Keywords(Reserved-words)
    if ( isLetter(peek) ) {
        ID(pos);
        return 0;
    }

    if ( isDigit(peek) ) {
        NUMBER(pos);
        return 0;
    }

    // if doesn't match any state, skip
    (*pos)++;

    return 1;
}

bool isLetter(char ch) {
    if ( (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') )
    {
        return 1;
    }
    return 0;
}

bool isDigit(char ch) {
    if ( ch >= '0' && ch <= '9' ) {
        return 1;
    }
    return 0;
}

bool isLetterOrDigit(char ch) {
    return isLetter(ch) || isDigit(ch);
}

bool ID(int *pos) {
    char peek = srcFile[(*pos)];
    tokenLength = 0;
    // get the whole identifier
    while ( isLetterOrDigit(peek) ) {
        tokenBuffer[tokenLength] = peek;
        tokenLength++;
        (*pos)++;
        peek = srcFile[(*pos)];
    }

    // diff keywords from identifier
    if ( isInKWTable(tokenBuffer, tokenLength) ) {
        int typeId = getKWtokenType(tokenBuffer, tokenLength);
        printf("%d %d\n", typeId, 0);
        return 0;
    } else {    // is just an identifier
    int tokenTextID = STableAddToken(tokenBuffer, tokenLength);
        printf("%d %d\n", 10, tokenTextID);
    }

    // output normal identifier for test
    // printTokenBufferForTest();

    return 0;
}

bool NUMBER(int *pos) {
    char peek;
    tokenLength = 0;    // clean tokenBuffer

    // get the Number ( INT or REAL )
    int state = 20; // in fact, the state is "Next-State"
    while (true) {
        switch (state) {
            case 20:
                peek = srcFile[(*pos)];
                if ( isDigit(peek) ) {
                    tokenBuffer[tokenLength++] = peek;
                    step(pos);
                    state = 20;
                } else if ( peek == '.' ) {
                    tokenBuffer[tokenLength++] = peek;
                    step(pos);
                    state = 22;
                } else {
                    // no need to step(pos) when meet "others"
                    // due to *
                    state = 21;
                }
                break;
            case 21:
                printTokenBufferForTest();
                // this is an accept state, so we will return
                return 0;
            case 22:
                peek = srcFile[(*pos)];
                if ( isDigit(peek) ) {
                    tokenBuffer[tokenLength++] = peek;
                    step(pos);
                    state = 23;
                } else {
                    // i don't know how to handle "others" here
                }
                break;
            case 23:
                peek = srcFile[(*pos)];
                if ( isDigit(peek) ) {
                    tokenBuffer[tokenLength++] = peek;
                    step(pos);
                    state = 23;
                } else {
                    // also no need to step(pos) here
                    state = 24;
                }
                break;
            case 24:
                printTokenBufferForTest();
                // this is an accept state, so we will return
                return 0;
            default:
                perror("Unreachable State");
        }
    }

    return 0;
}

void printTokenBufferForTest() {
    printf("token:");
    for ( int i = 0; i < tokenLength; i++ ) {
        printf("%c", tokenBuffer[i]);
    }
    printf("\n");
}
