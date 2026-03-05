/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30400
 *
 * [541] 反转字符串 II
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
  string reverseStr(string s, int k)
  {
    for (int i = 0; i < s.size(); i += 2 * k)// 每次移动2k个位置
    {
      reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size())); // 反转前k个字符
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
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
