/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30404
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (68.04%)
 * Likes:    1814
 * Dislikes: 0
 * Total Accepted:    671.9K
 * Total Submissions: 987.6K
 * Testcase Example:  '[10,15,20]\n[1,100,1,1,1,100,1,1,100,1]'
 *
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
 *
 * 一旦你支付此费用，即可选择向上爬 一个 或者 两个 台阶。
 *
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 *
 * 请你计算并返回达到楼梯顶部的 最低 花费，即最后一步之后的那个位置（下标 cost.length）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。
 * - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
 * 总花费为 15 。
 *
 *
 * 示例 2：
 *
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // vector<int> dp(n + 1);
        vector<int> dp(n + 1, -1);

        // dp[i]=min(dp[i-1]+cost[i-1],do[i-2]+cost[i-2]);
        // 如何到dp[i]=dp[i-1]+加上消耗的动作的 csot[i-1];
        // 如何到dp[i]=dp[i-2]+加上消耗的动作的 csot[i-2];

        // dp[0] = dp[1] = 0;
        // for (int i = 2; i <= n; i++)
        // {
        //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // }
        // return dp[n];
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 2)
                return 0;
            int &res = dp[i];
            if (res != -1)
                return res;
            res = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);
            return res;
        };
        return dfs(n);
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
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */
