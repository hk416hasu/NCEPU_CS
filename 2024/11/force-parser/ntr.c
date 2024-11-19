#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

FILE *fp_syn = NULL;

_Bool InitNTR() {
    fp_syn = fopen("./syntax.txt", "w");
        // error handle
    return 1;
}

void CloseNTR() {
    fclose(fp_syn);
}

_Bool isMatch(int expect) {
    int tokenType = atoi(tokenBuf);
    return ( tokenType == expect );
}

// warning : const num CAN NOT be a left-value
_Bool isMatchIDorINTorREAL() {
    return ( isMatch(10) || isMatch(11) || isMatch(12) );
}

void consume(int expect) {
    int tokenType = atoi(tokenBuf);
    if ( tokenType == expect ) {
        getNextToken();
    } else {
        fprintf(fp_syn, "error in consume()!\n");
        exit(1);
    }
}

void consumeAddorSub() {
    int tType = atoi(tokenBuf);
    if ( (tType == 14) || (tType == 15) ) {
        getNextToken();
    } else {
        fprintf(fp_syn, "error in consumeAddorSub()\n");
    }
}

void consumeMulorDiv() {
    int tType = atoi(tokenBuf);
    if ( (tType == 16) || (tType == 17) ) {
        getNextToken();
    } else {
        fprintf(fp_syn, "error in consumeMulorDiv()\n");
    }
}

void consumeIDorINTorREAL() {
    int tType = atoi(tokenBuf);
    if ( (tType == 10) || (tType == 11) || (tType == 12) ) {
        getNextToken();
    } else {
        fprintf(fp_syn, "error in consumeIDorINTorREAL()\n");
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
        fprintf(fp_syn, "Program\n");
    } else {
        fprintf(fp_syn, "error in Program()\n");
    }
}

_Bool StaList() {
    if ( isMatch(2) || isMatch(3) || isMatch(4)
            || isMatch(6) || isMatch(10) )
    {
        Statement();
        while (Statement());
        return 1;
    }
    return 0;
}

_Bool Statement() {
    if ( isMatch(2) || isMatch(3) ) { // if peek "int" or "float"
        DecSta();   return 1;
    } else if ( isMatch(10) ) { // const num CANNOT be left-val
        AssSta();   return 1;
    } else if ( isMatch(4) ) { // peek "if"
        IfSta();    return 1;
    } else if ( isMatch(6) ) { // peek "while"
        WhileSta(); return 1;
    }
    return 0;
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
        fprintf(fp_syn, "error in StaBlock()\n");
    }
}

void DecSta() {
    if ( isMatch(2) || isMatch(3) ) { // int or float
        DataType();
        VarList();
        consume(24); // ;
        fprintf(fp_syn, "DecSta\n");
    } else {
        fprintf(fp_syn, "error in DecSta()\n");
    }
}

_Bool VarList() {
    if ( isMatch(10) ) { // id
        consume(10);
        while ( isMatch(25) ) { // ,
            consume(25);
            consume(10);
        }
        return 1;
    }
    return 0;
}

void DataType() {
    if ( isMatch(2) ) { // int
        consume(2);
    } else if ( isMatch(3) ) { // float
        consume(3);
    } else {
        fprintf(fp_syn, "error in Datatype()\n");
    }
}

void AssSta() {
    if ( isMatch(10) ) { // id
        consume(10); // id
        consume(13); // =
        Exp();
        consume(24); // ;
        fprintf(fp_syn, "AssSta\n"); 
    } else {
        fprintf(fp_syn, "error in AssSta()\n");
    }
}

void IfSta() {
    if ( isMatch(4) ) { // if
        consume(4); // if
        consume(26); // (
        BoolExp();
        consume(27); // )
        StaBlock();
        if ( isMatch(5) ) {
            consume(5);
            StaBlock();
        }
        fprintf(fp_syn, "IfSta\n");
    } else {
        fprintf(fp_syn, "error in IfSta()\n");
    }
}

void WhileSta() {
    if ( isMatch(6) ) { // while
        consume(6); // while
        consume(26); // (
        BoolExp();
        consume(27); // )
        StaBlock();
        fprintf(fp_syn, "WhileSta\n");
    } else {
        fprintf(fp_syn, "error in WhileSta()\n");
    }
}

void Exp() {
    if ( isMatchIDorINTorREAL() || isMatch(26) ) {
        Item();
        while ( isMatch(14) || isMatch(15) ) { // + or -
            consumeAddorSub();
            Item();
        }
        fprintf(fp_syn, "Exp\n");
    } else {
        fprintf(fp_syn, "error in Exp()\n");
    }
}

void Exp_noOutput() {
    if ( isMatchIDorINTorREAL() || isMatch(26) ) {
        Item();
        while ( isMatch(14) || isMatch(15) ) { // + or -
            consumeAddorSub();
            Item();
        }
    } else {
        fprintf(fp_syn, "error in Exp()\n");
    }
}

void Item() {
    if ( isMatchIDorINTorREAL() || isMatch(26) ) { // id*3 or (
        Factor();
        while ( isMatch(16) || isMatch(17) ) {
            consumeMulorDiv();
            Factor();
        }
    } else {
        fprintf(fp_syn, "error in Item()\n");
    }
}

void Factor() {
    if ( isMatchIDorINTorREAL() ) {
        consumeIDorINTorREAL();
    } else if ( isMatch(26) ) { // (
        consume(26); // (
        Exp_noOutput();
        consume(27); // )
    } else {
        fprintf(fp_syn, "error in Factor()\n");
    }
}

void BoolExp() {
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolItem();
        while (isMatch(7)) {
            consume(7);
            BoolItem();
        }
        fprintf(fp_syn, "BoolExp\n");
    } else {
        fprintf(fp_syn, "error in BoolExp()\n");
    }
}

void BoolItem() {
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolFactor();
        while (isMatch(8)) {
            BoolFactor();
        }
    } else {
        fprintf(fp_syn, "error in BoolItem()\n");
    }
}

void BoolFactor() {
    if ( isMatch(9) ) { // !
        consume(9);
        RelExp();
    } else if ( isMatchIDorINTorREAL() ) {
        RelExp();
    } else {
        fprintf(fp_syn, "error in BoolFactor()\n");
    }
}

void RelExp() {
    if ( isMatchIDorINTorREAL() ) {
        consumeIDorINTorREAL();
        Relop();
        consumeIDorINTorREAL();
    } else {
        fprintf(fp_syn, "error in RelExp()\n");
    }
}

void Relop() {
    if ( isMatch(18) ) { // <
        consume(18);
    } else if ( isMatch(19) ) { // <=
        consume(19);
    } else if ( isMatch(20) ) { // >
        consume(20);
    } else if ( isMatch(21) ) { // >=
        consume(21);
    } else if ( isMatch(22) ) { // ==
        consume(22);
    } else if ( isMatch(23) ) { // !=
        consume(23);
    } else {
        fprintf(fp_syn, "error in Relop()\n");
    }
}
