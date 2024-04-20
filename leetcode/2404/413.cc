#include <iostream>
#include <vector>

#define len 9

int main() {
    int nums[len] = {1, 2, 3, 4, 5, 19, 20, 30, 40};
    /*
    std::vector<int> subAS_num(len+1);
    int base = 1, bias = 2;
    subAS_num[0] = 0;
    for (int i = 1; i <= len; i++) {
        subAS_num[i] = base;
        base += bias++;
    }
    */

    int sum = 0;
    std::vector<int> dp;
    dp.push_back(0);
    dp.push_back(0);
    for (int i = 2; i < len; i++) {
        if ( (nums[i]-nums[i-1]) == (nums[i-1]-nums[i-2]) ) {
            dp.push_back(dp.back() + 1);
        } else {
            dp.push_back(0);
        }
        sum += dp.back();
    }
    /*
    std::vector<int> dp2;
    for (int i = 3; i < len; i++) {
        if (dp[i] == 0 && dp[i-1] != 0) {
            dp2.push_back(dp[i-1]);
        }
    }
    dp2.push_back(dp.back());

    for (int val : dp2) {
        sum += subAS_num[val];
    }
    */
    printf("%d\n", sum);

    getchar();
    return 0;
}