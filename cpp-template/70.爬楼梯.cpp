/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30404
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (55.93%)
 * Likes:    4153
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 4.2M
 * Testcase Example:  '2\n3'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 45
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
    int climbStairs(int n)
    {
        // if (n < 2)
        //     return n;
        // vector<int> dp(n + 1);

        // dp[1] = 1;
        // dp[2] = 2;
        // for (int i = 3; i <= n; i++)
        // {
        //     dp[i] = dp[i - 2] + dp[i - 1];
        // };
        // return dp[n];
        vector<int> memo(n + 1, -1);
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 2)
                return i;
            int &res = memo[i];
            if (res != -1)
                return res;
            res = dfs(i - 1) + dfs(i - 2);
            return res;
        };
        return dfs(n + 2);
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

 */
