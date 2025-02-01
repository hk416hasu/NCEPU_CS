class Solution {
   public:
      int longestConsecutive(vector<int>& nums) {
         std::unordered_set<int> uset;
         for (int elem : nums) {
            uset.insert(elem);
         }

         int maxLength = 0;
         int length = 0;
         //for (int elem : nums) {
         for (const int &elem : uset) { // 去重
            if (uset.find(elem - 1) == uset.end()) { // 剪枝
                length = 0;
                int currElem = elem;
                while (uset.find(currElem) != uset.end()) {
                    length++;
                    currElem++;
                }
                maxLength = (maxLength > length) ? maxLength : length;
            }
         }
         return maxLength;
      }
};

