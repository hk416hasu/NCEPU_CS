#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

int partition(vector<int> &vec, int left, int right) {
   int pivot = vec[left];
   while (left < right) {
      while (left < right && vec[right] >= pivot) --right;
      vec[left] = vec[right];
      while (left < right && vec[left] <= pivot) left++;
      vec[right] = vec[left];
   }
   vec[left] = pivot;
   return left;
}

void quicksort(vector<int> &vec, int left, int right) {
   if (left < right) {
      int pos = partition(vec, left, right);
      quicksort(vec, left, pos-1);
      quicksort(vec, pos+1, right);
   }
}

int main() {
   vector<int> vec{4,4,4,4,8,5,3,0,6,7,2,1,9};
   quicksort(vec, 0, vec.size()-1);
   for (int elem : vec) {
      cout << elem << " ";
   }
   cout << endl;
   return 0;
}
