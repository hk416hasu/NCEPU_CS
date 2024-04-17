// longest non-increasing Subsquence, 动态规划求最大非递增子序列
#include <stdio.h>
#include <math.h>

#define num 6

void print(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findmax(int arr[], int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }
    return max;
}

int main() {
    int height[num] = {7,6,8,4,3,6};
    // int height[num] = {2,5,1,4,3,6};
    int dp[num] = {0};
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if ( (height[j] >= height[i]) && ((dp[j] + 1) > dp[i]) ) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    printf("the height array is: \n");
    print(height, num);
    printf("the dp array is: \n");
    print(dp, num);

    printf("the longest non-increasing subsquence length is: %d\n", findmax(dp, num));
    
    return 0;
}