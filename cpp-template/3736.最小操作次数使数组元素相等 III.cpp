/*
 * @lc app=leetcode.cn id=3736 lang=cpp
 * @lcpr version=30404
 *
 * [3736] 最小操作次数使数组元素相等 III
 *
 * https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-iii/description/
 *
 * algorithms
 * Easy (89.41%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    10.3K
 * Total Submissions: 11.5K
 * Testcase Example:  '[2,1,3]\n[4,4,5]'
 *
 * 给你一个整数数组 nums。
 *
 * 在一步操作中，你可以将任意单个元素 nums[i] 的值 增加 1。
 *
 * 返回使数组中的所有元素都 相等 所需的 最小总操作次数 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,1,3]
 *
 * 输出: 3
 *
 * 解释:
 *
 * 使所有元素相等的操作如下:
 *
 *
 * 将 nums[0] = 2 增加 1, 变为 3。
 * 将 nums[1] = 1 增加 1, 变为 2。
 * 将 nums[1] = 2 增加 1, 变为 3。
 *
 *
 * 现在，nums 中的所有元素都等于 3。最小总操作次数为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [4,4,5]
 *
 * 输出: 2
 *
 * 解释:
 *
 * 使所有元素相等的操作如下:
 *
 *
 * 将 nums[0] = 4 增加 1, 变为 5。
 * 将 nums[1] = 4 增加 1, 变为 5。
 *
 *
 * 现在，nums 中的所有元素都等于 5。最小总操作次数为 2。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 100
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
    int minMoves(vector<int> &nums)
    {
        int max = *max_element(nums.begin(), nums.end()); // 遍历数组，找到最大值
        int res = 0;
        for (int num : nums)
        {
            res += max - num; // 计算每个元素与最大值的差值，并累加到结果中
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
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,5]\n
// @lcpr case=end

 */
