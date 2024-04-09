// 求两序列的最大子段和
#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxsum = 0x80000000;
    for (int i = 0; i < num; i++) {
        // if (sum > 0) {  // 为什么是if(sum > 0)? 而不是 if(sum + arr[i] > sum) 即加入新元素比之前大？答：最优子结构决定的，前段和sum > 0才有必要保留。后者反例 -1 1
        if (sum + arr[i] > arr[i]) { // 但是这样也是可以的，因为是【前面+当前元素】不如【当前元素】大，因此舍弃前面的拖油瓶，从当前元素开始
            sum += arr[i];
        } else {
            sum = arr[i];   // 一开始我在此 sum = 0; 这句话对正结果成立，但对负结果不成立
        }
        if (sum > maxsum) { // 进行这个判断，以保留过程中得到的“最大sum”, 不然sum会随着遍历被更新
            maxsum = sum;
        }
    }

    printf("%d\n", maxsum);

    return 0;
}
