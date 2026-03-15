/*
 * @lc app=leetcode.cn id=917 lang=cpp
 * @lcpr version=30400
 *
 * [917] 仅仅反转字母
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
  string reverseOnlyLetters(string s)
  {
    int left = 0, right = s.size() - 1; // 双指针
    while (left < right) 
    {
      if (!isalpha(s[left])) // 非字母
      {
        left++; // 左指针右移
      }
      else if (!isalpha(s[right])) // 非字母
      {
        right--; // 右指针左移
      }
      else
      {
        swap(s[left], s[right]); // 交换字母 
        left++;
        right--;
      }
    }
    return s; 
  }
};
// @lc code=end

int main()
{
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// "ab-cd"\n
// @lcpr case=end

// @lcpr case=start
// "a-bC-dEf-ghIj"\n
// @lcpr case=end

// @lcpr case=start
// "Test1ng-Leet=code-Q!"\n
// @lcpr case=end

 */
