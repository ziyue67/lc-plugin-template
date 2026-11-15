/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30404
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (54.40%)
 * Likes:    2620
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[1,5,11,5]\n[1,2,3,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
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
    bool canPartition(vector<int> &nums)
    {
        int s = reduce(nums.begin(), nums.end(), 0);
        if (s % 2)
        {
            return false;
        }
        int n = nums.size();
        vector memo(n, vector<int>(s / 2 + 1, -1));
        auto dfs = [&](this auto &dfs, int i, int j) -> bool
        {
            if (i < 0)
            {
                return j == 0;
            }
            int &res = memo[i][j];
            if (res != -1)
            {
                return res;
            }
            // if (j < nums[i])
            // {
            //     return res = dfs(i - 1, j);
            // }
            res = j >= nums[i] && dfs(i - 1, j - nums[i]) || dfs(i - 1, j);
            return res;
        };
        return dfs(n - 1, s / 2);
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
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
