#include <iostream>

using std::cout;
using std::endl;

#define num 3

// int x[num+1] = {0,1,2,3,4,5,6,7,8,9,10};
int x[num+1] = {0,1,2,3};
int count = 0; // 计数器

void swap(int x[], int a, int b) {
    std::swap(x[a], x[b]);
}

void output(int x[]) {
    for (int i = 1; i <= num; i++) {
        printf("%d ", x[i]);
    }
}

/**
    @brief: 求x[n]的全排列
    @param: x[n] 是待排列数组序列
    @param: t 代表当前处于的解空间树层次
*/
void pailie(int x[], int t, int n) {
    if(t == (n+1)) {
        printf("reached the bottom, ready to output and get back\n");
        count++;
        for(int i = 1; i <= n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    } else {
        for(int i = t; i <= n; i++) {   // 处理元素[t]之下的元素
output(x); printf("before_FirstSwap: t = %d, i = %d\n", t, i);
            swap(x, t, i);      // 交换元素, 得新的排列解状态
output(x); printf("after_FirstSwap: t = %d, i = %d\n", t, i);
printf("trap in\n");
            pailie(x, t+1, n);  // 进入解空间树下一层
printf("get back\n");
output(x); printf("before_SecondSwap: t = %d, i = %d\n", t, i);
            swap(x, t, i);      // 状态回滚
output(x); printf("after_SecondSwap: t = %d, i = %d\n", t, i);
        }
    }
}

int main() {
    pailie(x, 1, num);
    cout << count << endl; // count == num!
    return 0;
}