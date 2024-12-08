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
        Opt_Else();
        fprintf(fp_syn, "IfSta\n");
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

#include <stdio.h>

// 全局变量
FILE *fp_dot;
int nodeCounter = 0; // 用于唯一标识每个节点
int currentParent = -1; // 当前父节点

// 初始化DOT文件
void initDotFile() {
    currentParent = -1;
    fp_dot = fopen("syntax_tree.dot", "w");
    fprintf(fp_dot, "digraph SyntaxTree {\n");
}

// 结束DOT文件
void closeDotFile() {
    fprintf(fp_dot, "}\n");
    fclose(fp_dot);
}

// 辅助函数
int createNode(const char *label) {
    int nodeId = nodeCounter++;
    fprintf(fp_dot, "  node%d [label=\"%s\"];\n", nodeId, label);
    return nodeId;
}

void connectNodes(int parent, int child) {
    if (parent != -1) {
        fprintf(fp_dot, "  node%d -> node%d;\n", parent, child);
    }
}

// 修改每个规则函数，插入DOT生成逻辑
void Exp() {
    int nodeId = createNode("Exp");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatchIDorINTorREAL() || isMatch(26)) {
        Item();
        An_Exp();
        fprintf(fp_syn, "Exp\n");
    } else {
        fprintf(fp_syn, "error in Exp()\n");
    }

    currentParent = prevParent;
}

void Exp_noOutput() {
    int nodeId = createNode("Exp_noOutput");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatchIDorINTorREAL() || isMatch(26)) {
        Item();
        An_Exp();
    } else {
        fprintf(fp_syn, "error in Exp_noOutput()\n");
    }

    currentParent = prevParent;
}

void An_Exp() {
    int nodeId = createNode("An_Exp");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatch(14) || isMatch(15)) { // + or -
        Suffix_Exp();
        An_Exp();
    } else if (isMatch(24) || isMatch(27)) {
        // do nothing
    } else {
        fprintf(fp_syn, "error in An_Exp()\n");
    }

    currentParent = prevParent;
}

void Suffix_Exp() {
    int nodeId = createNode("Suffix_Exp");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatch(14)) { // +
        consume(14);
    int nodeId = createNode("+");
    connectNodes(currentParent, nodeId);
        Item();
    } else if (isMatch(15)) { // -
        consume(15);
    int nodeId = createNode("-");
    connectNodes(currentParent, nodeId);
        Item();
    } else {
        fprintf(fp_syn, "error in Suffix_Exp()\n");
    }

    currentParent = prevParent;
}

void Item() {
    int nodeId = createNode("Item");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatchIDorINTorREAL() || isMatch(26)) {
        Factor();
        An_Item();
    } else {
        fprintf(fp_syn, "error in Item()\n");
    }

    currentParent = prevParent;
}

void An_Item() {
    int nodeId = createNode("An_Item");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatch(16) || isMatch(17)) { // * or /
        Suffix_Item();
        An_Item();
    } else if (isMatch(14) || isMatch(15) || // + or -
               isMatch(24) || isMatch(27)) { // ; or )
        // do nothing
    } else {
        fprintf(fp_syn, "error in An_Item()\n");
    }

    currentParent = prevParent;
}

void Suffix_Item() {
    int nodeId = createNode("Suffix_Item");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatch(16)) { // *
        consume(16);
    int nodeId = createNode("*");
    connectNodes(currentParent, nodeId);
        Factor();
    } else if (isMatch(17)) { // /
        consume(17);
    int nodeId = createNode("/");
    connectNodes(currentParent, nodeId);
        Factor();
    } else {
        fprintf(fp_syn, "error in Suffix_Item()\n");
    }

    currentParent = prevParent;
}

void Factor() {
    int nodeId = createNode("Factor");
    connectNodes(currentParent, nodeId);

    int prevParent = currentParent;
    currentParent = nodeId;

    if (isMatchIDorINTorREAL()) {
        consumeIDorINTorREAL();
    int nodeId = createNode("id");
    connectNodes(currentParent, nodeId);
    } else if (isMatch(26)) { // (
        consume(26); // (
        Exp_noOutput();
        consume(27); // )
    } else {
        fprintf(fp_syn, "error in Factor()\n");
    }

    currentParent = prevParent;
}

void BoolExp() {
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolItem();
        An_BoolExp();
        fprintf(fp_syn, "BoolExp\n");
    } else {
        fprintf(fp_syn, "error in BoolExp()\n");
    }
}

void An_BoolExp() {
    if ( isMatch(7) ) { // ||
        consume(7);
        BoolItem();
        An_BoolExp();
    } else if ( isMatch(27) ) { // )
        // do nothing
    } else {
        fprintf(fp_syn, "error in An_BoolExp()\n");
    }
}

void BoolItem() {
    if ( isMatchIDorINTorREAL() || isMatch(9) ) { // !
        BoolFactor();
        An_BoolItem();
    } else {
        fprintf(fp_syn, "error in BoolItem()\n");
    }
}

void An_BoolItem() {
    if ( isMatch(8) ) { // &&
        consume(8);
        BoolFactor();
        An_BoolItem();
    } else if ( isMatch(7) || isMatch(27) ) { // || or )
        // do nothing
    } else {
        fprintf(fp_syn, "error in An_BoolItem()\n");
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
