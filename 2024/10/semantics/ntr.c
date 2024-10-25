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

void consumeIDorINTorREAL() {
    int tType = atoi(tokenBuf);
    if ( (tType == 10) || (tType == 11) || (tType == 12) ) {
        getNextToken();
    } else {
        fprintf(fp_syn, "error in consumeIDorINTorREAL()\n");
    }
}

void Program() {
    getNextToken();
    if ( isMatch(1) ) { // if peek a "main"
        consume(1);  // main
        consume(26); // (
        consume(27); // )
        consume(28); // {
        StaList();
        consume(29); // }
        fprintf(fp_syn, "Program\n");
        // semantics
        genIR(88, 0, 0, 0);
    } else {
        fprintf(fp_syn, "error in Program()\n");
    }
}

void StaList() {
    if ( isMatch(2) || isMatch(3) || isMatch(4)
            || isMatch(6) || isMatch(10) )
    {
        Statement();
        Opt_StaList();
    } else {
        fprintf(fp_syn, "error in StaList()\n");
    }
}

void Opt_StaList() {
    if ( isMatch(29) ) { // if peek a "}"
        // do nothing, which mean N -> ε
    } else if ( isMatch(2) || isMatch(3) || isMatch(4)
            || isMatch(6) || isMatch(10) )
    {
        StaList();
    } else {
        fprintf(fp_syn, "error in StaList()\n");
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
        fprintf(fp_syn, "error in Statement()\n");
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

void VarList() {
    if ( isMatch(10) ) { // id
        consume(10);
        Opt_VarList();
    } else {
        fprintf(fp_syn, "error in VarList()\n");
    }
}

void Opt_VarList() {
    if ( isMatch(25) ) { // ,
        consume(25);
        VarList();
    } else if ( isMatch(24) ) { // ;
        // do nothing
    } else {
        fprintf(fp_syn, "error in Opt_VarList()\n");
    }
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
    int AssID = 0, child_ExpID = 0;
    if ( isMatch(10) ) { // id
        AssID = atoi(tIdBuf); assert(isInSTable(AssID));
        consume(10); // id
        consume(13); // =
        Exp(&child_ExpID);
        genIR(13, child_ExpID, 0, AssID);
        consume(24); // ;
        fprintf(fp_syn, "AssSta\n"); 
    } else {
        fprintf(fp_syn, "error in AssSta()\n");
    }
}

void IfSta() {
    int M = 0;
    struct set *BEtruelist = NULL;
    struct set *BEfalselist = NULL;
    if ( isMatch(4) ) { // if
        consume(4); // if
        consume(26); // (
        BoolExp(&BEtruelist, &BEfalselist);
        consume(27); // )
        M = getPC();
        StaBlock();
        Opt_Else();
        fprintf(fp_syn, "IfSta\n");

        assert(BEtruelist != NULL);
        // semantics
        backpatch(BEtruelist, M);

    } else {
        fprintf(fp_syn, "error in IfSta()\n");
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
    } else if ( isMatch(6) ) { // while
        // do nothing
    } else if ( isMatch(10) ) { // id
        // do nothing
    } else if ( isMatch(29) ) { // }
        // do nothing
    } else {
        fprintf(fp_syn, "error in Opt_Else()\n");
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

void Exp(int *id) {
    int child_ItemID = 0;
    int child_AnExpOP = 0, child_AnExpID = 0;
    if ( isMatchIDorINTorREAL() || isMatch(26) ) {
        Item(&child_ItemID);
        An_Exp(&child_AnExpOP, &child_AnExpID);
        fprintf(fp_syn, "Exp\n");
        if (child_AnExpOP != 0) {
            *id = newTemp();
            genIR(child_AnExpOP, child_ItemID,
                    child_AnExpID, *id);
        } else { // child_<An_Exp> → ε
            *id = child_ItemID;
        }
    } else {
        fprintf(fp_syn, "error in Exp()\n");
    }
}

void Exp_noOutput(int *id) {
    int child_ItemID = 0;
    int child_AnExpOP = 0, child_AnExpID = 0;
    if ( isMatchIDorINTorREAL() || isMatch(26) ) {
        Item(&child_ItemID);
        An_Exp(&child_AnExpOP, &child_AnExpID);
        if (child_AnExpOP != 0) {
            *id = newTemp();
            genIR(child_AnExpOP, child_ItemID,
                    child_AnExpID, *id);
        } else { // child_<An_Exp> → ε
            *id = child_ItemID;
        }
    } else {
        fprintf(fp_syn, "error in Exp_noOutput()\n");
    }
}

void An_Exp(int *op, int *id) {
    int child_SExpOP = 0, child_SExpID = 0;
    int child_AnExpOP = 0, child_AnExpID = 0;
    if ( isMatch(14) || isMatch(15) ) { // + or -
        Suffix_Exp(&child_SExpOP, &child_SExpID);
        An_Exp(&child_AnExpOP, &child_AnExpID);
        *op = child_SExpOP;
        if (child_AnExpOP != 0) {
            *id = newTemp();
            genIR(child_AnExpOP, child_SExpID,
                    child_AnExpID, *id);
        } else { // child_<An_Exp> → ε
            *id = child_SExpID;
        }
    } else if ( isMatch(24) || isMatch(27) ) {
        // do nothing
    } else {
        fprintf(fp_syn, "error in AnExp()\n");
    }
}

void Suffix_Exp(int *op, int *id) {
    if ( isMatch(14) ) { // +
        consume(14);
        *op = 14;
        Item(id);
    } else if ( isMatch(15) ) { // -
        consume(15);
        *op = 15;
        Item(id);
    } else {
        fprintf(fp_syn, "error in Suffix_Exp()\n");
    }
}

void Item(int *id) {
    int child_FactorID = 0;
    int child_AnItemOP = 0, child_AnItemID = 0;
    if ( isMatchIDorINTorREAL() || isMatch(26) ) { // id*3 or (
        child_FactorID = Factor();
        An_Item(&child_AnItemOP, &child_AnItemID);
        if (child_AnItemOP != 0) {
            *id = newTemp();
            genIR(child_AnItemOP, child_FactorID,
                    child_AnItemID, *id);
        } else { // child_<An_Item> → ε
            *id = child_FactorID;
        }
    } else {
        fprintf(fp_syn, "error in Item()\n");
    }
}

void An_Item(int *op, int *id) {
    int child_SItemOP = 0, child_SItemID = 0;
    int child_AnItemOP = 0, child_AnItemID = 0;
    if ( isMatch(16) || isMatch(17) ) { // * or /
        Suffix_Item(&child_SItemOP, &child_SItemID);
        An_Item(&child_AnItemOP, &child_AnItemID);
        *op = child_SItemOP;
        if (child_AnItemOP != 0) {
            *id = newTemp();
            genIR(child_AnItemOP, child_SItemID,
                    child_AnItemID, *id);
        } else { // child_<An_Item> → ε
            *id = child_SItemID;
        }
    } else if ( isMatch(14) || isMatch(15)  // + or -
            || isMatch(24) || isMatch(27) ) // ; or )
    {
        // do nothing
    } else {
        fprintf(fp_syn, "error in An_Item()\n");
    }
}

void Suffix_Item(int *op, int *id) {
    if ( isMatch(16) ) { // *
        consume(16);
        *op = 16;
        *id = Factor();
    } else if ( isMatch(17) ) { // /
        consume(17);
        *op = 17;
        *id = Factor();
    } else {
        fprintf(fp_syn, "error in Suffix_Item()\n");
    }
}

int Factor() {
    int id = 0;
    if ( isMatchIDorINTorREAL() ) {
        id = atoi(tIdBuf); assert(isInSTable(id));
        consumeIDorINTorREAL();
    } else if ( isMatch(26) ) { // (
        consume(26); // (
        Exp_noOutput(&id);
        consume(27); // )
    } else {
        fprintf(fp_syn, "error in Factor()\n");
    }
    return id;
}

void BoolExp(set_s **ptrue, set_s **pfalse) {
    struct set *BItruelist = NULL;
    struct set *BIfalselist = NULL;
    int child_M = 0;
    struct set *child_ABEtruelist = NULL;
    struct set *child_ABEfalselist = NULL;

    // parser
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolItem(&BItruelist, &BIfalselist);
        An_BoolExp(&child_M,
                &child_ABEtruelist, &child_ABEfalselist);
        // semantics
        if (child_M == 0) {
            *ptrue = BItruelist;
            *pfalse = BIfalselist;
        } else {
            backpatch(BIfalselist, child_M);
            *pfalse = child_ABEfalselist;
            merge(ptrue, BItruelist, child_ABEtruelist);
        }
        fprintf(fp_syn, "BoolExp\n");
    } else {
        fprintf(fp_syn, "error in BoolExp()\n");
    }
}

void An_BoolExp(int *pM, set_s **ptrue, set_s **pfalse) {
    int M = 0;
    struct set *BItruelist = NULL;
    struct set *BIfalselist = NULL;
    int child_M = 0;
    struct set *child_ABEtruelist = NULL;
    struct set *child_ABEfalselist = NULL;

    // parser
    if ( isMatch(7) ) { // ||
        consume(7);
        M = getPC();
        BoolItem(&BItruelist, &BIfalselist);
        An_BoolItem(&child_M,
                &child_ABEtruelist, &child_ABEfalselist);
        // semantics
        if (child_M == 0) {
            *ptrue = BItruelist;
            *pfalse = BIfalselist;
        } else {
            backpatch(BIfalselist, child_M);
            *pfalse = child_ABEfalselist;
            merge(ptrue, BItruelist, child_ABEtruelist);
        }
        *pM = M;
    } else if ( isMatch(27) ) { // )
        // do nothing for parser
        *pM = 0; // for semantics
    } else {
        fprintf(fp_syn, "error in An_BoolExp()\n");
    }
}

void BoolItem(set_s **ptrue, set_s **pfalse) {
    struct set *BFtruelist = NULL;
    struct set *BFfalselist = NULL;
    int child_M = 0; // but BoolItems needn't synthesize this
    struct set *child_ABItruelist = NULL;
    struct set *child_ABIfalselist = NULL;

    // parser
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolFactor(&BFtruelist, &BFfalselist);
        An_BoolItem(&child_M,
                &child_ABItruelist, &child_ABIfalselist);
        // semantics
        if (child_M == 0) {
            *ptrue = BFtruelist;
            *pfalse = BFfalselist;
        } else {
            backpatch(BFtruelist, child_M);
            *ptrue = child_ABItruelist;
            merge(pfalse, BFfalselist, child_ABIfalselist);
        }
    } else {
        fprintf(fp_syn, "error in BoolItem()\n");
    }
}

void An_BoolItem(int *pM, set_s **ptrue, set_s **pfalse) {
    int M = 0;
    struct set *BFtruelist = NULL;
    struct set *BFfalselist = NULL;
    int child_M = 0;
    struct set *child_ABItruelist = NULL;
    struct set *child_ABIfalselist = NULL;

    // parser
    if ( isMatch(8) ) { // &&
        consume(8);
        M = getPC();
        BoolFactor(&BFtruelist, &BFfalselist);
        An_BoolItem(&child_M,
                &child_ABItruelist, &child_ABIfalselist);
        // semantics
        if (child_M == 0) {
            *ptrue = BFtruelist;
            *pfalse = BFfalselist;
        } else {
            backpatch(BFtruelist, child_M);
            *ptrue = child_ABItruelist;
            merge(pfalse, BFfalselist, child_ABIfalselist);
        }
        *pM = M;
    } else if ( isMatch(7) || isMatch(27) ) { // || or )
        // do nothing for parser
        *pM = 0; // for semantics
    } else {
        fprintf(fp_syn, "error in An_BoolItem()\n");
    }
}

void BoolFactor(set_s **ptrue, set_s **pfalse) {
    if ( isMatch(9) ) { // !
        consume(9);
        RelExp(pfalse, ptrue);
    } else if ( isMatchIDorINTorREAL() ) {
        RelExp(ptrue, pfalse);
    } else {
        fprintf(fp_syn, "error in BoolFactor()\n");
    }
}

void RelExp(set_s **ptrue, set_s **pfalse) {
    struct set *truelist = newSet();
    struct set *falselist = newSet();
    int op = 0, id1 = 0, id2 = 0;
    if ( isMatchIDorINTorREAL() ) {
        id1 = atoi(tIdBuf); assert(isInSTable(id1));
        consumeIDorINTorREAL(); // id1
        op = Relop();
        id2 = atoi(tIdBuf); assert(isInSTable(id2));
        consumeIDorINTorREAL(); // id2
        // semantics
        addNewElemToSet(truelist, getPC());
        addNewElemToSet(falselist, getPC()+1);
        genIR(op, id1, id2, -1);
        genIR(30, 0, 0, -1);
        // synthesize
        *ptrue = truelist;
        *pfalse = falselist;
    } else {
        fprintf(fp_syn, "error in RelExp()\n");
    }
}

int Relop() {
    int op = 0;
    if ( isMatch(18) ) { // <
        consume(18); op = 18;
    } else if ( isMatch(19) ) { // <=
        consume(19); op = 19;
    } else if ( isMatch(20) ) { // >
        consume(20); op = 20;
    } else if ( isMatch(21) ) { // >=
        consume(21); op = 21;
    } else if ( isMatch(22) ) { // ==
        consume(22); op = 22;
    } else if ( isMatch(23) ) { // !=
        consume(23); op = 23;
    } else {
        fprintf(fp_syn, "error in Relop()\n");
    }
    return op;
}
