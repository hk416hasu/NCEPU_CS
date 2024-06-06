#include <iostream>

#define ElemType int

// 归并排序
// Merge函数很精巧 所以注意下边界条件和++吧，反正挺简洁的😂
void Merge(ElemType arr[], int low, int high) {
    int len = high-low+1;
    ElemType tmp[high];
    for(int i=0; i<=high; ++i) {
        tmp[i] = arr[i];
    }

    // 以下核心！！！！！
    int i,j,k;
    int mid = (low+high)/2;
    for(i=low,j=mid+1,k=i; i<=mid&&j<=high; ++k) {
        if(tmp[i]<=tmp[j]) {
            arr[k] = tmp[i++];
        } else {
            arr[k] = tmp[j++];
        }
    } 
    while(i <= mid) { arr[k++] = tmp[i++]; }
    while(j <= high) { arr[k++] = tmp[j++]; }
}

void MergeSort(ElemType arr[], int low, int high) {
    if(low<high) {
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,high);
    }
}
// 归并排序入口
void MergeSort(ElemType arr[], int len) {
    MergeSort(arr,0,len-1);
}

int main() {
    int arr[10] = {8,5,10,1,4,7,2,3,6,9};
    MergeSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}