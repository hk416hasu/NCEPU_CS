// Non-Terminal Recursion-funcs
#ifndef NTR_H
#define NTR_H

_Bool InitNTR();
void CloseNTR();

void Program();
_Bool StaList();
_Bool Statement();
void StaBlock();
void DecSta();
_Bool VarList();
void DataType();
void AssSta();
void IfSta();
void Opt_Else();
void WhileSta();
void Exp();
void An_Exp();
void Suffix_Exp();
void Item();
void An_Item();
void Suffix_Item();
void Factor();
void BoolExp();
void An_BoolExp();
void BoolItem();
void An_BoolItem();
void BoolFactor();
void RelExp();
void Relop();

#endif
