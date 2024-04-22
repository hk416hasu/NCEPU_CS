#include <stdio.h>

int main() {
    printf("To calculate the max_subarray_sum.\n");
    printf("plz input the len of original array:\n");
    int len = 0;
    scanf("%d", &len);
    printf("plz enter the original array's elems:\n");
    int arr[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    int dp[len];
    dp[0] = arr[0];
    int maxsum = dp[0];
    for (int i = 1; i < len; i++) {
        dp[i] = (dp[i-1] > 0) ? arr[i] + dp[i-1] : arr[i];
        maxsum = (maxsum > dp[i]) ? maxsum : dp[i];
    }

    printf("the max_subarray_sum is:%d\n", maxsum);

    return 0;
}