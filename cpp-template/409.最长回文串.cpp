/*
 * @lc app=leetcode.cn id=409 lang=cpp
 * @lcpr version=30403
 *
 * [409] 最长回文串
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_map"
#include "algorithm"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> map;
      for (auto c : s) {
        map[c]++;
      }
      int res=0;
      for(auto& [key , value] : map) {
        if(value % 2 == 0) {
          res += value;
        } else {
          res += value - 1;
        }
        
      }
      return res < s.size() ? res + 1 : res;
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "abccccdd"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

