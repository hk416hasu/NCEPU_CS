class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap; // key, anagrams

        for (const string &elem : strs) {
           string key = elem;
           sort(key.begin(), key.end());
           umap[key].emplace_back(elem);
        }

        vector<vector<string>> ret;
        for (auto elem : umap) {
           ret.emplace_back(elem.second);
        }
        return ret;
    }
};

