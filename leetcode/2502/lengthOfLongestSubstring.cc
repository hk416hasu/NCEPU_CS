#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::cout, std::unordered_set, std::endl, std::string;

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

int main() {
   // int len = lengthOfLongestSubstring("abcabcbb");
   int len = lengthOfLongestSubstring("dvdf");
   cout << len << endl;
   return 0;
}
