// 本算法假设 1.序列A中元素仅使用一次 2.均为正整数
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

int main() {
    int n = 0;  // 元素个数
    int target = 0; // 目标和
    scanf("%d %d", &n, &target);
    assert(n > 0);
    std::vector<int> A(n+1); // A存储了n个data，下标1-n有效
    // for (int i = 1; i <= n; i++) {
    //     scanf("%d", &A[i]);
    // }
    std::iota(A.begin(), A.end(), 0);

    // dp[i][j]表示"有i个数(1~i), target == j" 的解数
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(target + 1));
    // 初始化，第一列全为1，因为若target是0, 有且只有1个解就是所有元素都不取（!!仅考虑A[i]中都是正整数）
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    /*
    最优子结构说明：
        对于第n个数A[n], 有两种情况：
            1. 不取A[n], 则转为求子问题"对剩余n-1个数，求目标和为target"的解个数;
            2. 取A[n], 则问题转为求"对剩余n-1个数，求目标和为target-A[i]"的解个数;
        因此，dp[i][j] = dp[i-1][j] + dp[i-1][j-A[i]] (下标合法 且 A[i]<=target情况下);
        本质上类似于0-1背包问题，目标和target就是我们的背包大小。
        
        递推公式：
                    dp[i-1][j], A[i] > target时
        dp[i][j] =  dp[i-1][j], (A[i] <= target) && ((j-A[i]) < 0) 时;
                    dp[i-1][j] + dp[i-1][j-A[i]], (A[i] <= target) && ((j-A[i]) >= 0)时
    */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (A[i] > target) {    
                dp[i][j] = dp[i-1][j];
            } else {
                if (j-A[i] >= 0) {  // 如果j-A[i]合法
                    dp[i][j] = dp[i-1][j-A[i]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    printf("%d\n", dp[n][target]);

    getchar();
    return 0;
}