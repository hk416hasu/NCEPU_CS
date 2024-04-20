#include <vector>
#include <iostream>
#include <cmath>

int main() {
    int n = 13;
    
    // 1. 稍显暴力
    // int len = n + 1;
    // std::vector<int> dp(len, INT_MAX);
    // for (int i = 1; i <= (int)sqrt(n); i++) {
    //     dp[i * i] = 1;
    // }
    // dp[0] = 0;
    // for (int i = 2; i < len; i++) {
    //     if (dp[i] == 1) { continue; }
    //     for (int j = 1; j <= i/2; j++) {
    //         dp[i] = fmin(dp[i], dp[j]+dp[i-j]);
    //     }
    // }

    // 2. 既然题目只允许 m = n + 1/4/9/16...， 那么 dp[m] 就和 dp[m-1]/dp[m-4]/dp[m-9]... 相关了！最优子结构找到。其实类似于爬楼梯
    if (n < 1) { return 0; }
    std::vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = fmin(dp[i], dp[i-(j*j)]);
        }
        dp[i]++;
    }
    getchar();
    return 0;
}