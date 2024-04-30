#include <vector>
#include <iostream>
#include <assert.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    assert(n > 0);

    std::vector<std::vector<int>> data(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    dp.back().assign(data.back().begin(), data.back().end());
    
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

    getchar();
    return 0;
}

// 5
// 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5