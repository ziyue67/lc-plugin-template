/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30404
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (71.40%)
 * Likes:    2755
 * Dislikes: 0
 * Total Accepted:    577K
 * Total Submissions: 808.1K
 * Testcase Example:  '3\n1'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：5
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 19
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
    int numTrees(int n)
    {

        // 1. 动态规划  i..........i， i-1
        //   j..............j,j-1
        vector<int> dp(n + 1, 0);    // dp[i] 表示由 i 个节点组成的不同二叉搜索树的个数
        dp[0] = 1;                   // 空树也算一种二叉搜索树
        dp[1] = 1;                   // 只有一个节点时，只有一种二叉搜索树
        for (int i = 2; i <= n; i++) // 计算由 i 个节点组成的不同二叉搜索树的个数
        {
            int sum = 0;                 // 计算由 i 个节点组成的不同二叉搜索树的个数
            for (int j = 1; j <= i; j++) // 以 j 为根节点，左子树有 j-1 个节点，右子树有 i-j 个节点
            {
                sum += dp[j - 1] * dp[i - j]; //  左子树的不同二叉搜索树的个数 * 右子树的不同二叉搜索树的个数
            }
            dp[i] = sum;
        }
        return dp[n];
    }
}

;
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
