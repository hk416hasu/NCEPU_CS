#include <iostream>
#include <cstdio>
#include <vector>

int partition(std::vector<int> &vec, int left, int right) {
   int pivot = vec[left];
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
   if (left < right) {
      int pivotPos = partition(vec, left, right);
      quicksort(vec, left, pivotPos - 1);
      quicksort(vec, pivotPos + 1, right);
   }
}

void quicksort(std::vector<int> &vec) {
   quicksort(vec, 0, vec.size() - 1);
}

int main() {
   std::vector<int> vec = {4, 2, 5, 9, 10, 0, 8, 7, 233};
   quicksort(vec);
   for (int elem : vec) {
      printf("%d ", elem);
   }
   puts("");
   return 0;
}
