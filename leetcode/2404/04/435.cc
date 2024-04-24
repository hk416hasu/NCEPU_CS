#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

struct {
    bool operator()(vector<int> &a, vector<int> &b) const {
        return a[1] < b[1];
    }
} customLess;

int main() {
    vector<vector<int>> intervals = { {3,4}, {2,3}, {-2,3}, {1,2} };
    // 按结束时间排序(升序)
    // 我仿照cpp reference写的排序(自己写的函数对象)，性能很糟糕啊 // 没有引用导致的
    std::sort(intervals.begin(), intervals.end(), customLess);
    
    // 抄的排序(lambda表达式函数对象)，性能怎么这么优秀？！
                                    // 引用！它用了引用！
    // sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
    //     return u[1] < v[1];
    // });

    int select_num = 1;
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= right) {
            select_num++;
            right = intervals[i][1];
        }
        // 经过证明（看题解），只用看右边就行
        // if (intervals[i][1] <= left) {
            // select_num++;
            // left = intervals[i][0];
        // }
    }

    printf("%d\n", intervals.size() - select_num);

    getchar();
    return 0;
}