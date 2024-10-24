// Non-Terminal Recursion-funcs
#ifndef NTR_H
#define NTR_H

#include "set.h"

_Bool InitNTR();
void CloseNTR();
void Program();
void StaList();
void Opt_StaList();
void Statement();
void StaBlock();
void DecSta();
void VarList();
void Opt_VarList();
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
//void BoolExp(set_s **ptrue, set_s **pfalse);
void BoolExp();
void An_BoolExp(int *pM, set_s **ptrue, set_s **pfalse);
void BoolItem(set_s **ptrue, set_s **pfalse);
void An_BoolItem(int *pM, set_s **ptrue, set_s **pfalse);
void BoolFactor(set_s **ptrue, set_s **pfalse);
void RelExp(set_s **ptrue, set_s **pfalse);
int Relop();

#endif
