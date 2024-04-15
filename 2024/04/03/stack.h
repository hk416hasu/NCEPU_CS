#include <stdbool.h>

#define MaxSize 100
#define ElemType int

typedef struct SqStack{
    ElemType data[MaxSize];
    int top;    // 栈顶指针 
} SqStack;

bool InitStack(SqStack *S) {
    S->top = 0; // 初始化指向位序0
    return true;
}

bool EmptyStack(SqStack *S) {
    if (S->top == 0) { return true; }
    return false;
}

bool Push(SqStack *S, ElemType *data) {
    if (S->top == MaxSize) { return false; }
    S->data[S->top++] = *data;
    return true;
}

bool Pop(SqStack *S, ElemType *data) {
    if (EmptyStack(S)) { return false; }
    *data = S->data[--S->top];
    return true;
}

// ? 不就是pop么...
bool GetTop_Rm(SqStack *S, ElemType *data) {
    if (EmptyStack(S)) {
        return false;
    }
    *data = S->data[--S->top];
    return true;
}