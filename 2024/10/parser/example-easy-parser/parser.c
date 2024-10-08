#include <stdio.h>
#include <stdlib.h>

// the tokens
char inputType[] = { '(', '(', 'a', '+', 'a', ')', '+', 'a', ')' };
int peek = 0;

char token;

/**
brief: return the next token from array or file or something else
    so u can wait for lexer here, by a file-lock or others
    */
char getNextToken() {
    return inputType[peek++];
}

/**
brief: try to match the "actual obtained Token" with "expecting Terminal"
    if matched, then getNextToken()
    if not, then print error
    */
void match(char expectedTerminal) {
    if ( token == expectedTerminal ) {
        token = getNextToken();
    } else {
        // perror("the curr token is: xxx");
        // perror("the expected terminal is : yyy");
        exit(1);
    }
}

/*------------- write a resursion func for each non-terminal -------------*/ 

void F() {
    if ( token == 'a' ) {
        match('a');
    } else {
        // some error messages
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
        // some error messages
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
