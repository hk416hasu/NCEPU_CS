#include <iostream>
#include <cstdio>
#include <vector>

int count = 0;
std::vector<int> vec;

// num为当前数值，target为目标和
void func(int num, int target) {
    // 出口
    if (num <= 0 || target <= 0) {
        return;
    }
    // 当num等于目标target时，就输出
    if (num == target) {
        count++;
        for (auto elem : vec) {
            printf("%d ", elem);
        }
        printf("%d\n", num);
    }
    // 对于元素i，有两种情况
        // 1. 选中i, 那么问题就转变为对剩余i-1个数求target-A[i]的解
        // 2. 不选i, 那么问题就转变为对剩余i-1个数求target的解
        // 本质是前序遍历/DFS一大堆状态
    vec.push_back(num);
    func(num - 1, target - num);
    vec.pop_back();
    func(num - 1, target);
}

int main() {
    int n = 0, target = 0;
    scanf("%d %d", &n, &target);
    func(n, target);
    printf("Here are %d solutions.\n", count);
    return 0;
}