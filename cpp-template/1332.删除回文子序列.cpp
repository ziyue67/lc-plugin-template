/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 * @lcpr version=30401
 *
 * [1332] 删除回文子序列
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
      int left = 0, right = s.size() - 1;
      while (left<right)
      {
        if(s[left]!=s[right]){ // 
          return 2; // 不是回文子序列
        }
        left++;
        right--;
      }
      return 1; // 是回文子序列

      
        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "ababa"\n
// @lcpr case=end

// @lcpr case=start
// "abb"\n
// @lcpr case=end

// @lcpr case=start
// "baabb"\n
// @lcpr case=end

 */

