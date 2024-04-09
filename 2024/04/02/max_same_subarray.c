// 求两序列最长相同子序列（动态规划）
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define len1 11
#define len2 10

#define MaxSize 100
#define ElemType char

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


int main() {
    char s1[len1] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '\0'};
    char s2[len2] = {'h', 'o', 'l', 'l', 'a', 'w', 'o', 'r', 'd', '\0'};
    printf("%s\n%s\n", s1, s2);
    int dp[len1][len2] = {0};
    int trace[len1][len2] = {0};
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                trace[i][j] = 1;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    trace[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j-1];
                    trace[i][j] = 3;
                }
            }
        }
    }

    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    int i = len1 - 1, j = len2 - 1;
    SqStack S;
    InitStack(&S);
    ElemType ch;
    while (i > 0 && j > 0) {
        switch (trace[i][j]) {
        case 1:
            ch = s1[i-1];
            Push(&S, &ch);
            i--; j--;
            break;
        case 2: i--; break;
        case 3: j--; break;
        default: break;
        }
    }

    char substr[MaxSize];
    for (i = 0; !EmptyStack(&S); i++) {
        Pop(&S, &ch);
        substr[i] = ch;
    }
    substr[i] = '\0';
    printf("%s\n", substr);

    return 0;
}