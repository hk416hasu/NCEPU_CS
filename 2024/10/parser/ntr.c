#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

_Bool isMatch(int expect) {
    int tokenType = atoi(tokenBuf);
    return ( tokenType == expect );
}

// warning : const num CAN NOT be a left-value
_Bool isMatchIDorINTorREAL() {
    int tokenType = atoi(tokenBuf);
    return ( isMatch(10) || isMatch(11) || isMatch(12) );
}

void consume(int expect) {
    int tokenType = atoi(tokenBuf);
    if ( tokenType == expect ) {
        getNextToken();
    } else {
        printf("error in consume()!\n");
        exit(1);
    }
}

void consumeIDorINTorREAL() {
    int tType = atoi(tokenBuf);
    if ( (tType == 10) || (tType == 11) || (tType == 12) ) {
        getNextToken();
    } else {
        printf("error in consumeIDorINTorREAL()\n");
    }
}

void Program() {
    if ( isMatch(1) ) { // if peek a "main"
        consume(1);  // main
        consume(26); // (
        consume(27); // )
        consume(28); // {
        StaList();
        consume(29); // }
        printf("Program\n");
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
        // do nothing, which mean N -> ε
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
        printf("error in Statement()\n");
    }
}

void StaBlock() {
    if ( isMatch(2) || isMatch(3) || isMatch(4) \
            || isMatch(6) || isMatch(10) )
    {
        Statement();
    } else if ( isMatch(28) ) { // {
        consume(28); // {
        StaList();
        consume(29); // }
    } else {
        printf("error in StaBlock()\n");
    }
}

void DecSta() {
    if ( isMatch(2) || isMatch(3) ) { // int or float
        DataType();
        VarList();
        consume(24); // ;
        printf("DecSta\n");
    } else {
        printf("error in DecSta()\n");
    }
}

void VarList() {
    if ( isMatch(10) ) { // id
        consume(10);
        Opt_VarList();
    } else {
        printf("error in VarList()\n");
    }
}

void Opt_VarList() {
    if ( isMatch(25) ) { // ,
        consume(25);
        VarList();
    } else if ( isMatch(24) ) { // ;
        // do nothing
    } else {
        printf("error in Opt_VarList()\n");
    }
}

void DataType() {
    if ( isMatch(2) ) { // int
        consume(2);
    } else if ( isMatch(3) ) { // float
        consume(3);
    } else {
        printf("error in Datatype()\n");
    }
}

void AssSta() {
    if ( isMatch(10) ) { // id
        consume(10); // id
        consume(13); // =
        Exp();
        consume(24); // ;
        printf("AssSta\n"); 
    } else {
        printf("error in AssSta()\n");
    }
}

void IfSta() {
    if ( isMatch(4) ) { // if
        consume(4); // if
        consume(26); // (
        BoolExp();
        consume(27); // )
        StaBlock();
        Opt_Else();
        printf("IfSta\n");
    } else {
        printf("error in IfSta()\n");
    }
}

void Opt_Else() {
    if ( isMatch(5) ) { // else
        consume(5); // else
        StaBlock();
    } else if ( isMatch(2) ) { // int
        // do nothing
    } else if ( isMatch(3) ) { // float
        // do nothing
    } else if ( isMatch(4) ) { // if
        // do nothing
    } else {
        printf("error in Opt_Else()\n");
    }
}

void WhileSta() {
    if ( isMatch(6) ) { // while
        consume(6); // while
        consume(26); // (
        BoolExp();
        consume(27); // )
        StaBlock();
        printf("WhileSta\n");
    } else {
        printf("error in WhileSta()\n");
    }
}

void Exp() {
    if ( isMatchIDorINTorREAL() || is Match(26) ) {
        Item();
        An_Exp();
        printf("Exp\n");
    } else {
        printf("error in Exp()\n");
    }
}

void An_Exp() {
    if ( isMatch(14) || isMatch(15) ) { // + or -
        Suffix_Exp();
        An_Exp();
    } else if ( isMatch(24) || isMatch(27) ) {
        // do nothing
    } else {
        printf("error in AnExp()\n");
    }
}

void Suffix_Exp() {
    if ( isMatch(14) ) { // +
        consume(14);
        Item();
    } else if ( isMatch(15) ) { // -
        consume(15);
        Item();
    } else {
        printf("error in Suffix_Exp()\n");
    }
}

void Item() {
    if ( isMatchIDorINTorREAL() || isMatch(26) ) { // id*3 or (
        Factor();
        An_Item();
    } else {
        printf("error in Item()\n");
    }
}

void An_Item() {
    if ( isMatch(16) || isMatch(17) ) { // * or /
        Suffix_Item();
        An_Item();
    } else if ( isMatch(14) || isMatch(15) \ // + or -
            || isMatch(24) || isMatch(27) ) // ; or )
    {
        // do nothing
    } else {
        printf("error in An_Item()\n");
    }
}

void Suffix_Item() {
    if ( isMatch(16) ) { // *
        consume(16);
        Factor();
    } else if ( isMatch(17) ) { // /
        consume(17);
        Factor();
    } else {
        printf("error in Suffix_Item()\n");
    }
}

void Factor() {
    if ( isMatchIDorINTorREAL() ) {
        consumeIDorINTorREAL();
    } else if ( isMatch(26) ) { // (
        consume(26); // (
    } else {
        printf("error in Factor()\n");
    }
}

