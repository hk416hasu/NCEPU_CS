#include <stdio.h>
#include <stdlib.h>

// the tokens
char inputType[] = { '(', '(', 'a', '+', 'a', ')', '+', 'a', ')' };
int peek = 0;

char token;

// return the next token, get it from array or file or something else
char getNextToken() {
    return inputType[peek++];
}

/**
brief: try to match the "expecting Terminal" with the "actual obtained Token"
    if matched, then getNextToken()
    if not, then print error
    */
void match(char ch) {
    if ( ch == token ) {
        token = getNextToken();
    } else {
        exit(1);
    }
}

/*------------- write a resursion func for each non-terminal -------------*/ 

void F() {
    if ( token == 'a' ) {
        match('a');
    } else {
        exit(1);
    }
    // echo its name before return
    printf("F\n");
}

void S() {
    if ( token == '(' ) {
        match('(');
        S();
        match('+');
        F();
        match(')');
    } else if ( token == 'a' ) {
        F();
    } else {
        exit(1);
    }
    // echo its name before return
    printf("S\n");
}

int main() {

    token = getNextToken();
    S();    // start from the START, a Non-Terminal

    return 0;
}
