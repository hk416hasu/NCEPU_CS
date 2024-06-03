#include <iostream>

using std::cout;
using std::endl;

#define num 4

// int x[num+1] = {0,1,2,3,4,5,6,7,8,9,10};
int x[num+1] = {0,1,2,3,4};
int count = 0; // 计数器

void swap(int x[], int a, int b) {
    std::swap(x[a], x[b]);
}

void pailie(int x[], int t, int n)
{
    if(t > n) {
        // output x[]
        count++;
        for(int i = 1; i <= n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    } else {
        for(int i = t; i <= n; i++) {
            swap(x, t, i);  // 交换元素, 得新的排列树
            pailie(x, t+1, n);
            swap(x, t, i);  // 状态回滚
        }
    }
}

int main() {
    pailie(x, 1, num);
    cout << count << endl; // count == num!
    return 0;
}