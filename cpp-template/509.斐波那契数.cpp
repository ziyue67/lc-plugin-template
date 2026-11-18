/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30404
 *
 * [509] 斐波那契数
 *
 * https://leetcode.cn/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (65.29%)
 * Likes:    918
 * Dislikes: 0
 * Total Accepted:    977.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '2\n3\n4'
 *
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 *
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 *
 *
 * 给定 n ，请计算 F(n) 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 *
 *
 * 示例 3：
 *
 * 输入：n = 4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 30
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
    int fib(int n)
    {
        // if (n < 2)
        // {
        //     return n;
        // }
        // vector<int> dp(n + 1);
        // // // dp[i-1]+dp[i-2]
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++)
        // {

        //     int sum = dp[0] + dp[1];
        //     dp[0] = dp[1];
        //     dp[1] = sum;
        // }
        // return dp[1];
        // for (int i = 2; i <= n; i++)
        // {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // };
        // return dp[n];
        vector<int> memo(n + 1, -1);
        function<int(int)> helper = [&](int i) -> int
        {
            if (i < 2)
            {
                return i;
            }
            int &res = memo[i];
            if (res != -1)
            {
                return res;
            }
            res = helper(i - 1) + helper(i - 2);
            return res;
        };
        return helper(n);
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
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
