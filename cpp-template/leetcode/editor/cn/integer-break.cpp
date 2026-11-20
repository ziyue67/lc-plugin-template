/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30404
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (65.11%)
 * Likes:    1566
 * Dislikes: 0
 * Total Accepted:    460.4K
 * Total Submissions: 707.2K
 * Testcase Example:  '2\n10'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 *
 * 返回 你可以获得的最大乘积 。
 *
 *
 *
 * 示例 1:
 *
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= n <= 58
 *
 *
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
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        // dp[i]=max(j *(i-j) ,j*dp[i-j], dp[i])
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max({j * (i - j), j * dp[i - j], dp[i]});
            }
        }
        return dp[n];
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
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
