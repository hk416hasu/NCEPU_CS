#include <vector>

using std::vector;
#define len 4

int Optimal_index(vector<int> &arr) {
    int OpIndex = 0;
    for (int i = 1; i < arr.size(); i++) {
        OpIndex = (arr[i] < arr[OpIndex]) ? i : OpIndex;
    }
    return OpIndex;
}

int main() {
    
    int p[len + 1] = {25,10,5,30,10};

    int dp[len][len] = {0};
    vector<int> vec;

    for (int offset = 1; offset < len; offset++) {
        for (int i = 0; i + offset < len; i++) {
            vec.clear();
            int j = i + offset;

            for (int k = i; k < j; k++) {
                vec.push_back(dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1]);
            }

            dp[i][j] = vec[(Optimal_index(vec))];
        }
    }


    return 0;
}