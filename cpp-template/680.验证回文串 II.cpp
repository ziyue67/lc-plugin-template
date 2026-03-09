/*
 * @lc app=leetcode.cn id=680 lang=cpp
 * @lcpr version=30400
 *
 * [680] 验证回文串 II
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
  bool isPalindrome(const string &s, int left, int right)
  {
    while (left < right)
    {
      if (s[left] != s[right])
      {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  bool validPalindrome(string s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
      if (s[left] != s[right])
      {
        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
      }
      left++;
      right--;
    }
    return true;
  }
};

// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

