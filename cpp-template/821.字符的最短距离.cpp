/*
 * @lc app=leetcode.cn id=821 lang=cpp
 * @lcpr version=30400
 *
 * [821] 字符的最短距离
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
  vector<int> shortestToChar(string s, char c)
  {
    int n = s.size();
    vector<int> res(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
      if (s[i] == c)
      {
        res[i] = 0;
        for (int j = i - 1; j >= 0; j--)
        {
          res[j] = min(res[j], i - j);
        }
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == c)
      {
        for (int j = i + 1; j < n; j++)
        {
          res[j] = min(res[j], j - i);
        }
      }
    }
    return res;
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
// "loveleetcode"\n"e"\n
// @lcpr case=end

// @lcpr case=start
// "aaab"\n"b"\n
// @lcpr case=end

 */
