// longest non-increasing Subsquence, 动态规划求最大非递增子序列
#include <stdio.h>
#include <math.h>

#define num 8

void print(int arr[], int len) {
    printf("\t");
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
    int height[num] = {389,207,155,300,299,170,158,65};
    // int height[num] = {7,6,8,4,3,6};
    // int height[num] = {2,5,1,4,3,6};
    int dp[num] = {0};
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if ( (height[j] >= height[i]) && ((dp[j] + 1) > dp[i]) ) {  // 如果可以的话，尽可能延续最优解
                dp[i] = dp[j] + 1;
            }
        }
    }

    printf("the height array is: \n");
    print(height, num);
    printf("the dp array is: \n");
    print(dp, num);

    printf("the longest non-increasing subsquence length is: %d\n", findmax(dp, num));

    int min_num = 1;    // 最少使用导弹系统数
    for (int i = 1; i < num; i++) {
        if (dp[i] < dp[i-1]) {   // 根据dp数组求
       	// if (height[i] > height[i-1]) {  // 根据原height数组求
            min_num++;
        }
    }
    printf("At least, we need %d systems.\n", min_num);

    return 0;
}
