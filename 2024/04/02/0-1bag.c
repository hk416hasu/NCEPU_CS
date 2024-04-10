/*
    0-1背包问题
    dp[i][j]含义：i为背包容量，j为物品个数(A1 - Aj), dp[i][j]就是在“容量为i的背包”中“装下A1至Aj这些个物品”的最大价值；
    最优子结构是：对于第j个物品，装？or不装？谁更大？max{dp[i-wj][j-1] + pj, dp[i][j-1]};
                装：容量减小，价值增加，更新dp值  ；不装：容量与价值均不变，dp值等于装到第j-1个物品
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mem.h>

void Input(int *arr, int len) {
    arr[0] = 0;
    for (int i = 1; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int capacity = 0, num = 0;
    scanf("%d%d", &capacity, &num);
    int n_len = num + 1;
    int c_len = capacity + 1;

    int *weight = (int *)malloc(n_len * sizeof(int));
    Input(weight, n_len);
    int *price = (int *)malloc(n_len * sizeof(int));
    Input(price, n_len);


    // int dp[c_len][n_len];
    // memset(dp, 0, c_len * n_len * sizeof(int));
    // int trace[c_len][n_len];
    // memset(trace, 0, c_len * n_len * sizeof(int));
    // int *select = (int *)malloc(n_len * sizeof(int));
    // memset(select, 0, c_len * sizeof(int));

    int w = 0, p = 0;
    for (int i = 1; i < c_len; i++) {
        for (int j = 1; j < n_len; j++) {
            w = weight[j];
            p = price[j];
            if (w > i) {
                dp[i][j] = dp[i][j-1];
                trace[i][j] = 0;
            } else {
                if (dp[i-w][j-1] + p > dp[i][j-1]) {
                    dp[i][j] = dp[i-w][j-1] + p;
                    trace[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                    trace[i][j] = 0;
                }
            }
        }
    }
    printf("dp:\n");
    for (int i = 0; i < c_len; i++) {
        for (int j = 0; j < n_len; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\ntrace:\n");
    for (int i = 0; i < c_len; i++) {
        for (int j = 0; j < n_len; j++) {
            printf("%d ", trace[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = capacity, j = num; j > 0; j--) {
        if (trace[i][j] == 1) {
            select[j] = 1;
            i -= weight[j];
        }
    }
    for (int i = 1; i < n_len; i++) {
        if (select[i] == 1) {
            printf("A%d ", i);
        }
    }
    printf("\n");

    getchar();
    return 0;
}

/*

10 5
3 2 4 1 6
10 7 12 4 20

*/