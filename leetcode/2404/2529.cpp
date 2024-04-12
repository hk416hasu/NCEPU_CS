class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // 思路是二分找“最后一个负数位置 high”，然后再遍历找第一个大于0的数

        int len = nums.size();
        int high = len - 1;
        int low = 0, mid = 0;
        int neg = 0, pos = 0; // 负数个数neg， 正数个数pos
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        neg = high + 1;

        int i = neg;
        for (; i < len; i++) {
            if (nums[i] == 0)
                continue;
            else
                break;
        }
        pos = len - i;

        return max(pos, neg);
    }
};