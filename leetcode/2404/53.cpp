// 求最大子段和
class Solution1 {
public:
    // 最呆的初版
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

class Solution2 {
public:
    // cpoy来的
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

class Solution3 {
public:
    // 自己两周之后再写的
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxsum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = (sum > 0) ? sum + nums[i] : nums[i];
            maxsum = fmax(sum, maxsum);
        }
        return maxsum;
    }
};

int main() {
    // 完整版
    // 如果过去是拖累，则全部舍弃，重置为当前值；如果过去有增益，则保留，+= 当前值。
    // if sum <= 0 ,则 sum = curr; if sum > 0, 则 sum += curr.
    printf("To calculate the max_subarray_sum.\n");
    printf("plz input the len of original array:\n");
    int len = 0;
    scanf("%d", &len);
    printf("plz enter the original array's elems:\n");
    int arr[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    int dp[len];
    dp[0] = arr[0];
    int maxsum = dp[0];
    for (int i = 1; i < len; i++) {
        dp[i] = (dp[i-1] > 0) ? arr[i] + dp[i-1] : arr[i];
        maxsum = (maxsum > dp[i]) ? maxsum : dp[i];
    }

    printf("the max_subarray_sum is:%d\n", maxsum);

    return 0;
}