// 最长公共子序列
#include <iostream>
#include <vector>
#include <cmath>

// #define max(a,b) (((a) > (b)) ? (a) : (b))

using std::vector;

int main() {
    vector<char> A {'A', 'C', 'A', 'D', 'B'};
    vector<char> B {'C', 'B', 'D', 'A'};

    // vector<char> A {'A', 'B'};
    // vector<char> B {'B', 'C'};

    int lenA = A.size();
    int lenB = B.size();

    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            // if (A[i] == B[j]) {  // 由于串AB的长度与dp不统一, 需要一些转换
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


getchar();
    return 0;
}   