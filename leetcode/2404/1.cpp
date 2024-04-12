class Solution {
public:
    int findNum(vector<int>& nums, int target, int begin) {
        for (int i = begin; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        } 
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ab;
        int index_t = -1;
        for (int i = 0; i < nums.size() && ab.size() == 0; i++) {
            index_t = findNum(nums, target - nums[i], i + 1);
            if (index_t != -1) {
                ab.push_back(i);
                ab.push_back(index_t);
            }
        }
        return ab;
    }
};