// 窗口优化
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int maxLen = 0;
        int r = 0;
        for (int i = 0; i < s.size(); i++) {
            while (r < s.size() && !uset.count(s[r])) {
                uset.insert(s[r]);
                r++;
            }
            maxLen = std::max(maxLen, r - i);
            uset.erase(s[i]);
        }
        return maxLen;
    }
};

// 原始解法
int lengthOfLongestSubstring_original(string s) {
    unordered_set<char> uset;
    int len = 0, maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        int r = i;
        uset.clear();
        len = 0;
        while (r < s.size() && !uset.count(s[r])) {
            uset.insert(s[r]);
            len++;
            r++;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

