#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMax(const vector<int>& arr, int left, int right) {
    // 基本情况：只有一个元素
    if (left == right) {
        return arr[left];
    }

    // 找到中间点
    // int mid = left + (right - left) / 2;
    int mid = (right + left) / 2;

    // 递归求左半部分的最大值
    int maxLeft = findMax(arr, left, mid);

    // 递归求右半部分的最大值
    int maxRight = findMax(arr, mid + 1, right);

    // 返回两者中较大的值
    return max(maxLeft, maxRight);
}

int main() {
    vector<int> arr = {1, 5, 90, 7, 0, 2, 8, 4, 6, 0};
    int n = arr.size();
    int maxVal = findMax(arr, 0, n - 1);
    cout << "The maximum value in the array is: " << maxVal << endl;
    return 0;
}
