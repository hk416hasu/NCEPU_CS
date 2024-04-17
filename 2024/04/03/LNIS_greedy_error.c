// 贪心无法求最长非递增子序列(至少我还不知道)
#include <stdio.h>

#define num 6

int main() {
    int arr[num] = {7,6,8,4,3,6};
    int sum = 0, maxsum = 0;
    
    for (int j = num-1; j >= 0; j--) {
        sum = 0;
        int pre = arr[j];
        for (int i = j; i >= 0; i--) {
            if (arr[i] >= pre) {
                sum++;
                pre = arr[i];
            }
        }
        maxsum = (maxsum > sum) ? maxsum : sum;
    }

    printf("%d\n", maxsum);

    return 0;
}