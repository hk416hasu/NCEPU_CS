class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> umap; // value, index
      for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (umap.find(complement) != umap.end()) {
          return {umap[complement], i};
        }
        umap.insert({nums[i], i});
      }
      return {};
    }
};
