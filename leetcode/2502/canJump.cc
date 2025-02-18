#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

bool canJump(vector<int>& nums) {
   int maxPos = 0 + nums[0];
   for (int i = 0; i <= maxPos && i < nums.size(); i++) {
      maxPos = std::max(maxPos, i + nums[i]);
   }
   return maxPos >= nums.size()-1;
}

int main() {
   vector<int> nums = {1, 2, 3};
   std::cout << canJump(nums) << std::endl;
   return 0;
}
