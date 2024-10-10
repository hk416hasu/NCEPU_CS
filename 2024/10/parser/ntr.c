#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

_Bool isMatch(int expect) {
    int tokenType = atoi(tokenBuf);
    return ( tokenType == expect );
}

// warning : const num CAN NOT be a left-value
_Bool isMatchIdentifier() {
    int tokenType = atoi(tokenBuf);
    return ( isMatch(10) || isMatch(11) || isMatch(12) );
}

void match(int expect) {
    int tokenType = atoi(tokenBuf);
    if ( tokenType == expect ) {
        getNextToken();
    } else {
        printf("error in match()!\n");
        exit(1);
    }
}

void Program() {
    if ( isMatch(1) ) { // if peek a "main"
        match(1);   // main
        match(26);  // (
        match(27);  // )
        match(28);  // {
        StaList();
        match(29);  // }
        fprintf(fp, "Program\n");
    } else {
        printf("error in Program()\n");
    }
}

void StaList() {
    if ( isMatch(2) || isMatch(3) || isMatch(4) \ 
            || isMatch(6) || isMatch(10) )
    {
        Statement();
        Opt_StaList();
    } else {
        printf("error in StaList()\n");
    }
}

void Opt_StaList() {
    if ( isMatch(29) ) { // if peek a "}"
        return;
    } else if ( isMatch(2) || isMatch(3) || isMatch(4) \ 
            || isMatch(6) || isMatch(10) )
    {
        StaList();
    } else {
        printf("error in StaList()\n");
    }
}

void Statement() {
    if ( isMatch(2) || isMatch(3) ) { // if peek "int" or "float"
        DecSta();
    } else if ( isMatch(10) ) { // const num CANNOT be left-val
        AssSta();
    } else if ( isMatch(4) ) { // peek "if"
        IfSta();
    } else if ( isMatch(6) ) { // peek "while"
        WhileSta();
    } else {
        printf("error in Statement\n");
    }
}
