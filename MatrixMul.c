#include <stdio.h>
#include <string.h>

#define Max 5
int Matrix[Max+1], dp[Max][Max], trace[Max][Max];

void func(const int num) {
    memset(dp, 0, Max * Max * sizeof(int)); // 初始化整个dp数组及其对角线（虽然全局数组初始值也是 0 ）
    for (int offset = 1; offset < num; offset++) {
        for (int i = 0; i < num - offset; i++) {
            int j = i + offset;
            // 这两重for循环可以斜线访问dp数组了!（跳过对角线）

            int k = i;  // 首先从i开始断开(初始值)，找最优解
            dp[i][j] = dp[i][k] + dp[k+1][j] + Matrix[i] * Matrix[k+1] * Matrix[j+1];
            trace[i][j] = k;
            for (; k < j; k++) {    // 更新找最小（最优解）
                int tmp = dp[i][k] + dp[k+1][j] + Matrix[i] * Matrix[k+1] * Matrix[j+1];
                if (tmp < dp[i][j]) {
                    dp[i][j] = tmp;
                    trace[i][j] = k;
                }
            }
        }
    }
}
// (二叉树后根遍历)得到矩阵相乘顺序
void traceback(int begin, int end) {
    if (begin != end) {
        traceback(begin, trace[begin][end]);
        traceback(trace[begin][end] + 1, end);
        printf("Matrix_%d * Matrix_%d\n", begin, end);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i <= num; i++) {
        scanf("%d", &Matrix[i]);
    }
    func(num);
    traceback(0, num - 1);

    return 0;
}

// 5 5 10 8 50 6 10