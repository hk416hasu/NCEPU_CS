// 数字三角形的最大路径和（动态规划）
#include <stdio.h>
#include <math.h>
#include "stack.h"

#define num 4   // 三角形行数

int main() {
    SqStack S;
    InitStack(&S);
    int val[num][num+1] = {{0,1,0,0,0},{0,3,2,0,0},{0,4,10,1,0},{0,4,3,2,10}};
    int dp[num][num+1] = {0};
    bool trace[num][num+1] = {0};

    // 得到dp数组
    dp[0][1] = val[0][1];
    for (int i = 1; i < num; i++) {
        for (int j = 1; j <= i+1; j++) {
            if (dp[i-1][j-1] > dp[i-1][j]) {
                trace[i][j] = 0;
                dp[i][j] = dp[i-1][j-1] + val[i][j];
            } else {
                trace[i][j] = 1;
                dp[i][j] = dp[i-1][j] + val[i][j];
            }
        }   
    }

    // traceback
    int max_i = 0, max_j = 0;
    int max = dp[num-1][1];
    for (int i=num-1, j=2; j <= num; j++) {
        if (dp[i][j] > max) {
            max = dp[i][j];
            max_i = i;
            max_j = j;
        }
    }
    int tmp = max;
    for (int i=max_i, j=max_j; i >= 0;) {
        tmp = val[i][j];
        Push(&S, &tmp);
        if (trace[i][j] == 1) {
            i--;
        } else {
            i--;
            j--;
        }
    }
    int max_sum = 0;
    while (Pop(&S, &tmp)) {
        max_sum += tmp;
        printf("%d ", tmp);
    }
    printf("\nmax_sum = %d\n", max_sum);
    
    return 0;
}