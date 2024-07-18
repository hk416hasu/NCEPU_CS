// 最长非递增子序列
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using std::vector;

int main() {
    // vector<int> height {389, 207, 155, 300, 299, 170, 158, 65};
    vector<int> height {1,2,3,4,5,6,7};
    assert(height.size() > 0);

    vector<int> dp(height.size());
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++) {
        int tmp = 0;
        for (int k = 0; k < i; k++) {
            if (height[k] >= height[i]) {
                tmp = std::max(tmp, dp[k]);
            }
        }
        dp[i] = tmp + 1;
    }

getchar();
    return 0;
}   