/*
 * @lc app=leetcode.cn id=338 lang=cpp
 * @lcpr version=30404
 *
 * [338] 比特位计数
 *
 * https://leetcode.cn/problems/counting-bits/description/
 *
 * algorithms
 * Easy (78.91%)
 * Likes:    1448
 * Dislikes: 0
 * Total Accepted:    414.3K
 * Total Submissions: 525.1K
 * Testcase Example:  '2\n5'
 *
 * 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans
 * 作为答案。
 *
 * 不要使用内置函数来解决（例如，C++ 中的 __builtin_popcount）。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：[0,1,1]
 * 解释：
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * 示例 2：
 *
 * 输入：n = 5
 * 输出：[0,1,1,2,1,2]
 * 解释：
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？
 *
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
    vector<int> countBits(int n)
    {
        vector<int> memo(n + 1, -1);
        auto dfs = [&](this auto &&dfs, int i) -> int
        {
            if (i == 0)
            {
                return 0;
            }
            int &res = memo[i];
            if (res != -1)
            {
                return res;
            }
            return res = dfs(i >> 1) + (i & 1);
        };
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            res[i] = dfs(i);
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
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */
