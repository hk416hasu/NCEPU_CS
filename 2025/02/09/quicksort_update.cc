#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

void insertSort(std::vector<int> &vec, int left, int right) {
   for (int i = left+1; i <= right; i++) {
      int curr = vec[i];
      int j = i - 1;
      for (; j >= left && vec[j] > curr; j--) {
         vec[j+1] = vec[j];
      }
      vec[j+1] = curr;
   }
}

int partition(std::vector<int> &vec, int left, int right) {
   int mid = midpoint(left, right);
   // [left], [mid], [right] 取中位数
   int pivot = std::max(std::min(vec[left], vec[mid]), std::min(std::max(vec[left], vec[mid]), vec[right]));
   while (left < right) {
      while (left < right && vec[right] >= pivot) right--;
      vec[left] = vec[right];
      while (left < right && vec[left] <= pivot) left++;
      vec[right] = vec[left];
   }
   vec[left] = pivot;
   return left;
}

void quicksort(std::vector<int> &vec, int left, int right) {
   while (left < right) { // 递归转循环, 降低递归深度
      if (right - left <= 16) { // 小规模用插入排序加速
         insertSort(vec, left, right);
         return;
      }
      int pivotPos = partition(vec, left, right);
      if (pivotPos - left < right - pivotPos) { // 递归小规模
         quicksort(vec, left, pivotPos - 1);
         left = pivotPos + 1; // 大规模用循环处理
      } else {
         quicksort(vec, pivotPos + 1, right);
         right = pivotPos - 1;
      }
   }
}

void quicksort(std::vector<int> &vec) {
   quicksort(vec, 0, vec.size() - 1);
}

int main() {
   std::vector<int> vec = {4, 2, 5, 9, 10, 0, 8, 7, 233};
   quicksort(vec, 0, vec.size() - 1);
   for (int elem : vec) {
      printf("%d ", elem);
   }
   puts("");
   return 0;
}
