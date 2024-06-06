#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

size_t partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    // while (low <= high) {    // 实践表明此处 low <= high 不可行
    while (low < high) {    // 我们希望最终 low == high, 指向pivot应在的位置
        while (low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

// 每趟确定一个枢轴的位置, 然后分治
void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
    // if (low <= high) {   // 对于仅一个元素 不用处理直接返回即可; 想处理也可以
        size_t pivotpos = partition(arr, low, high);
        quicksort(arr, low, pivotpos - 1);
        quicksort(arr, pivotpos + 1, high);
    }
}

void quicksort(vector<int> &arr) {
    quicksort(arr, 0, arr.size() - 1);
}

void output(const vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

int main() {

    vector<int> arr {8,5,10,1,4,7,2,3,6,9};
    quicksort(arr);
    output(arr);

    return 0;
}