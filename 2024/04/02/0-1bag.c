/*
    0-1背包问题
    dp[i][j]含义：i为背包容量，j为物品个数(A1 - Aj), dp[i][j]就是在“容量为i的背包”中“装下A1至Aj这些个物品”的最大价值；
    最优子结构是：对于第j个物品，装？or不装？谁更大？max{dp[i-wj][j-1] + pj, dp[i][j-1]};
                装：容量减小，价值增加，更新dp值  ；不装：容量与价值均不变，dp值等于装到第j-1个物品
    遍历顺序：行从小到大，列从小到大；（由我找到的最优子结构 + 递推公式决定的）
    递推公式：
                        dp[i][j-1], i < wj 时
            dp[i][j] = 
                        max{dp[i-wj][j-1]+pj, dp[i][j-1]}, i >= wj 时


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mem.h>

#define capacity 10
#define c_len (capacity + 1)
#define num 5
#define n_len (num + 1)

void Output2Darray(int (*arr)[n_len], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int weight[n_len] = {0,3,2,4,1,6};
    int price[n_len] = {0,10,7,12,4,20};
    int dp[c_len][n_len] = {0};
    int trace[c_len][n_len] = {0};
    int select[n_len] = {0};
    int w = 0, p = 0;   // w 存储第j个物品的重量，p 存储第j个物品的价格

    // 动态规划主体：遍历得dp数组与trace数组
    for (int i = 1; i < c_len; i++) {
        for (int j = 1; j < n_len; j++) {
            w = weight[j];
            p = price[j];
            if (w > i) {
                dp[i][j] = dp[i][j-1];
                trace[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-w][j-1]+p > dp[i][j-1]) ? dp[i-w][j-1]+p : dp[i][j-1];
                trace[i][j] = (dp[i-w][j-1]+p > dp[i][j-1]) ? 1 : 0;
            }
        }
    }

    // 打印dp数组 与 trace数组
    printf("dp:\n");
    Output2Darray(dp, c_len, n_len);
    printf("trace:\n");
    Output2Darray(trace, c_len, n_len);

    // traceback and printout
    for (int i = capacity, j = num; j > 0; j--) {
        if (trace[i][j] == 1) {
            select[j] = 1;
            i -= weight[j];
        }
    }
    printf("optimal things: \n");
    for (int i = 1; i < n_len; i++) {
        if (select[i] == 1) {
            printf("A%d ", i);
        }
    }
    printf("\n\n");

    return 0;
}