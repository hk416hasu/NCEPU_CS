class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = 0x80000000;
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }

            if (sum > maxsum) {
                maxsum = sum;
            }
        }
        return maxsum;
    }
};