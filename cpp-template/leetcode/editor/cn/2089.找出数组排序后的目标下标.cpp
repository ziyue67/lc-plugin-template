/*
 * @lc app=leetcode.cn id=2089 lang=cpp
 * @lcpr version=30404
 *
 * [2089] 找出数组排序后的目标下标
 *
 * https://leetcode.cn/problems/find-target-indices-after-sorting-array/description/
 *
 * algorithms
 * Easy (79.02%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 45.6K
 * Testcase Example:  '[1,2,5,2,3]\n2\n[1,2,5,2,3]\n3\n[1,2,5,2,3]\n5'
 *
 * 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
 *
 * 目标下标 是一个满足 nums[i] == target 的下标 i 。
 *
 * 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增
 * 顺序排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,5,2,3], target = 2
 * 输出：[1,2]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 2 的下标是 1 和 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,5,2,3], target = 3
 * 输出：[3]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 3 的下标是 3 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,5,2,3], target = 5
 * 输出：[4]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 5 的下标是 4 。
 *
 *
 * 示例 4：
 *
 * 输入：nums = [1,2,5,2,3], target = 4
 * 输出：[]
 * 解释：nums 中不含值为 4 的元素。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i], target <= 100
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // void insertionSort(vector<int> &nums) // 插入排序
    // {
    //     int n = nums.size();
    //     for (int i = 1; i < n; i++)
    //     {
    //         int key = nums[i];
    //         int j = i - 1;
    //         while (j >= 0 && nums[j] > key)
    //         {
    //             nums[j + 1] = nums[j];
    //             j--;
    //         }
    //         nums[j + 1] = key;
    //     }
    // }
    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;

        int i = l, j = r;
        // 取中间位置作为基准，避免遇到有序数组时退化到 O(n^2)
        int pivot = nums[l + (r - l) / 2];

        while (i <= j)
        {
            while (nums[i] < pivot)
                ++i;
            while (nums[j] > pivot)
                --j;
            if (i <= j)
            {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }

        quickSort(nums, l, j);
        quickSort(nums, i, r);
    }
    vector<int>
    targetIndices(vector<int> &nums, int target)
    {
        // insertionSort(nums);

        // auto left = lower_bound(nums.begin(), nums.end(), target);
        // auto right = upper_bound(nums.begin(), nums.end(), target);

        // vector<int> res;
        // for (auto it = left; it != right; ++it)
        // {
        //     res.push_back(it - nums.begin());
        // }
        // return res;
        // sort(nums.begin(), nums.end()); // 最快速的
        // vector<int> res;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == target)
        //     {
        //         res.push_back(i);
        //     }
        // }
        // return res;

        // 方法三 手写快排 然后二分搜索
        quickSort(nums, 0, (int)nums.size() - 1);

        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        vector<int> res;
        for (auto it = left; it != right; ++it)
        {
            res.push_back(it - nums.begin());
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
// [1,2,5,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5,2,3]\n5\n
// @lcpr case=end

 */
