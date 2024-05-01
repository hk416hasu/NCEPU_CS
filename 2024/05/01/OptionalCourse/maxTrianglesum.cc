#include <vector>
#include <iostream>
#include <cassert>

int main() {
    int n = 0;  // 三角型行数
    scanf("%d", &n);
    assert(n > 0);  // 确保 n > 0

    std::vector<std::vector<int>> data(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    dp.back().assign(data.back().begin(), data.back().end());   // dp数组最后一行初始化为data的最后一行
    // dp.back() = data.back();    // vector的=运算符重载真好用

    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = data[i][j] + std::max(dp[i+1][j+1], dp[i+1][j]);
        }
    }

    // 贪心法traceback
    int i = -1, j = 0, curr = 0;
    do {
        if (dp[i+1][j+1] > dp[i+1][j]) {
            curr = data[++i][++j];
        } else {
            curr = data[++i][j];
        }
        printf("%d ", curr);
    } while (i < n-1);
    printf("\n");

    return 0;
}

// 5
// 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5