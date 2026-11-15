/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30404
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode.cn/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (67.92%)
 * Likes:    1970
 * Dislikes: 0
 * Total Accepted:    935.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '"abcde"\n"ace"\n"abc"\n"abc"\n"abc"\n"def"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 *
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 *
 *
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 *
 *
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：text1 = "abcde", text2 = "ace"
 * 输出：3
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 *
 *
 * 示例 3：
 *
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 和 text2 仅由小写英文字符组成。
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
    int longestCommonSubsequence(string text1, string text2)
    {
        // int n = text1.size();
        // int m = text2.size();
        // vector<int> dp(m + 1, 0);
        // for (int i = 1; i <= n; i++)
        // {
        //     int prev = 0;
        //     for (int j = 1; j <= m; j++)
        //     {
        //         int temp = dp[j];
        //         if (text1[i - 1] == text2[j - 1])
        //         {
        //             dp[j] = prev + 1;
        //         }
        //         else
        //         {
        //             dp[j] = max(dp[j], dp[j - 1]);
        //         }
        //         prev = temp;
        //     }
        // }
        // return dp[m];
        int n = text1.size(), m = text2.size();
        vector memo(n, vector<int>(m, -1)); // -1 表示没有计算过

        auto dfs = [&](this auto &dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0)
                return 0;
            int &res = memo[i][j]; // 引用计算过的 剪枝
            if (res != -1)
            {
                return res; // 计算过 直接提升算法效率
            }
            if (text1[i] == text2[j])
            {
                return res = dfs(i - 1, j - 1) + 1;
            }
            return res = max(dfs(i - 1, j), dfs(i, j - 1));
        };
        return dfs(n - 1, m - 1);
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
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */
