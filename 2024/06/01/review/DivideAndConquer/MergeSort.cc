#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

void output(const vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

void Merge(vector<int> &arr, int low, int high) {
    // 拷贝一份待处理数组, 待会从这里取数
    // int len = high - low + 1;
    vector<int> tmp(arr);
    // for (int i = low; i <= high; i++) {
    //     tmp[i] = arr[i];
    // }

    int mid = (low + high) / 2;
    int i = low, j = mid + 1, k = low;
    // for (i = low, j = mid; i < mid && j <= high; k++) {
    while (i <= mid && j <= high) {
        if (tmp[i] <= tmp[j]) {
            arr[k++] = tmp[i++];
        } else {
            arr[k++] = tmp[j++];
        }
    }

    while (i <= mid) arr[k++] = tmp[i++];
    while (j <= high) arr[k++] = tmp[j++];

}

// 分治: 分成两半递归地处理
void MergeSort(vector<int> &arr, int low, int high) {
    if (low < high) {   // 仅一元素时直接返回即可
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        // MergeSort(arr, low, mid - 1);    // 由于向下取整
        // MergeSort(arr, mid, high);
        Merge(arr, low, high);
    }
}

void MergeSort(vector<int> &arr) {
    MergeSort(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr {8,5,10,1,4,7,2,3,6,9};
    MergeSort(arr);
    output(arr);

    return 0;
}