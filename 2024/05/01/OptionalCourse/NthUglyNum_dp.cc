#include <iostream>
#include <vector>

typedef unsigned long long uLL;

int main() {
    int n = 0;
    scanf("%d", &n);
    std::vector<uLL> dp(n+1);
    dp[1] = 1;
    int i2 = 1, i3 = 1, i5 = 1;

    // 这么写是错的，不能正确去重
    // for (int i = 2; i <= n; i++) {
    //     if (dp[i2] * 2 < dp[i3] * 3) {
    //         dp[i] = dp[i2++] * 2;
    //     } else if (dp[i3] * 3 < dp[i5] * 5) {
    //         dp[i] = dp[i3++] * 3;
    //     } else {
    //         dp[i] = dp[i5++] * 5;
    //     }
    // }

    for (int i = 2; i <= n; i++) {
        uLL num2 = dp[i2] * 2, num3 = dp[i3] * 3, num5 = dp[i5] * 5;
        dp[i] = std::min(std::min(num2, num3), num5);
        if (dp[i] == num2) { i2++; }
        if (dp[i] == num3) { i3++; }
        if (dp[i] == num5) { i5++; }
    }

    printf("%llu\n", dp.back());

    return 0;
}