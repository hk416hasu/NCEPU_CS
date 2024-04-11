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


    优化思路：按列遍历，因为在我的“最优子结构”和“递推公式”中，i是安全的 不会越界访问，dp[i][j]只和上一列有关，所以我们最少只需要两列即可。

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mem.h>
#include <stdbool.h>

#define capacity 10
#define c_len (capacity + 1)
#define num 5
#define n_len (num + 1)

int main() {
    int weight[n_len] = {0,3,2,4,1,6};
    int price[n_len] = {0,10,7,12,4,20};
    int dp[c_len][2] = {0};
    bool trace[c_len][n_len] = {0};
    int select[n_len] = {0};
    int w = 0, p = 0;   // w 存储第j个物品的重量，p 存储第j个物品的价格

    // 动态规划主体：遍历得dp数组与trace数组
    for (int j = 0; j < n_len; j++) {
        for (int i = 0; i < c_len; i++) {
            w = weight[j];
            p = price[j];
            if (w > i) {
                dp[i][1] = dp[i][0];
                trace[i][j] = 0;
            } else {
                dp[i][1] = (dp[i-w][0]+p > dp[i][0]) ? dp[i-w][0]+p : dp[i][0];
                trace[i][j] = (dp[i-w][0]+p > dp[i][0]) ? 1 : 0;
            }
        }
        // 更新第0列，准备下一次遍历
        for (int i = 1; i < c_len; i++) {
            dp[i][0] = dp[i][1];
        }
    }

    // 打印dp数组（优化后只输出最后一列）
    printf("dp:\n");
    for (int i = 0; i < c_len; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

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