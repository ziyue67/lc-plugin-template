/*
 * @lc app=leetcode.cn id=557 lang=cpp
 * @lcpr version=30400
 *
 * [557] 反转字符串中的单词 III
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
  string reverseWords(string s)
  {
    int n = s.size(), i = 0; // i指向单词开头
    while (i < n)            // j指向单词结尾
    {            // 遍历字符串
      int j = i; // j指向单词结尾
      while (j < n && s[j] != ' ')
      { // 找到单词结尾
        j++;
      }
      reverse(s.begin() + i, s.begin() + j); // 反转单词
      i = j + 1;                             // i指向下一个单词开头
    }
    return s; // 返回结果
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
// "Let's take LeetCode contest"\n
// @lcpr case=end

// @lcpr case=start
// "Mr Ding"\n
// @lcpr case=end

 */
