// 斜线访问数组
#include<string.h>
#define num 6

int main() {
    int arr[num][num];
    memset(arr, 0, num * num * sizeof(int));
    int count = 1;

    for (int k = 0; k < num; k++) {
        for (int i = 0; i < num - k; i++) {
            arr[i][i + k] = count++;
        }
    }
    // 跳过主对角线
    // for (int k = 1; k < num; k++) {
    //     for (int i = 0; i < num - k; i++) {
    //         arr[i][i + k] = count++;
    //     }
    // }
    

    return 0;
}