class Solution {
   public:
      void moveZeroes(vector<int>& nums) {
         int p = 0, q = 0;
         while (q < nums.size()) {
            if (nums[q] != 0) {
               nums[p] = nums[q];
               p++;
            }
            q++;
         }
         for ( ; p < nums.size(); p++) {
            nums[p] = 0;
         }
      }
};
