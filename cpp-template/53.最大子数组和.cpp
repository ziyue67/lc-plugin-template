/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30404
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (56.96%)
 * Likes:    7527
 * Dislikes: 0
 * Total Accepted:    2.8M
 * Total Submissions: 4.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]\n[1]\n[5,4,-1,7,8]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
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
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        auto dfs = [&](this auto &&dfs, int i) -> int
        {
            if (i == 0)
            {
                return dp[i] = nums[0];
            }
            int &res = dp[i];
            if (res != -1)
            {
                return res;
            }
            res = dp[i] = max(nums[i], dfs(i - 1) + nums[i]);
            return res;
        };
        int ans = nums[0];
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(i));
        }
        return ans;
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
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
