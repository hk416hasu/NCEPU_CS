#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using std::vector;

int min_index(vector<int> vec) {
    assert(vec.size() > 0);
    int min_i = 0; 
    for (int i = 0; i < vec.size(); i++) {
        min_i = (vec[min_i] < vec[i]) ? min_i : i;
    }
    return min_i;
}

void traceback(vector<vector<int>> &trace, int begin, int end) {
    if (begin != end) {
        int BestPoint = trace[begin][end];  // trace中记录了最佳断开点
        traceback(trace, begin, begin + BestPoint);
        traceback(trace, begin + BestPoint + 1, end);
        printf("%d * %d\n", begin, end);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> Matrix(n+1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &Matrix[i]);
    }

    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> trace(n, vector<int>(n));
    vector<int> vec;    // 策略暂存数组

    // slash-visit
    for (int offset = 1; offset < n; offset++) {
        for (int i = 0; (i + offset) < n; i++) {
            vec.clear();
            int j = i + offset;
            for (int k = i; k < j; k++) {
                vec.push_back(Matrix[i] * Matrix[k+1] * Matrix[j+1] + dp[i][k] + dp[k+1][j]);
            }
            int index = min_index(vec);
            trace[i][j] = index;
            dp[i][j] = vec[index];
        }
    }

    traceback(trace, 0, n-1);
    
    printf("%d\n", dp[0][n-1]);

    return 0;
}
// 5 4 2 3 4 5 6
// 5 5 10 8 50 6 10
