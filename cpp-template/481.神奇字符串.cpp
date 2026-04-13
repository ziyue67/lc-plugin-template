/*
 * @lc app=leetcode.cn id=481 lang=cpp
 * @lcpr version=30403
 *
 * [481] 神奇字符串
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
  int magicalString(int n)
  {
    string s = "\1\2\2"; // 值就是 1,2,2，这样就可以直接用 s[i] 当作个数
    for (int i = 2; s.length() < n; ++i) // i 是 2 开始的，因为前两个已经初始化了
      s += string(s[i], s.back() ^ 3); // 1^3=2, 2^3=1，这样就能在 1 和 2 之间转换
    return count(s.begin(), s.begin() + n, 1); // 统计前 n 个字符中 1 的个数
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
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
