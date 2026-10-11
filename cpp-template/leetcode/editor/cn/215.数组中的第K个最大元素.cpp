/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30404
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (60.02%)
 * Likes:    3081
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3M
 * Testcase Example:  '[3,2,1,5,6,4]\n2\n[3,2,3,1,2,4,5,5,6]\n4'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;
#include <algorithm>
// @lc code=start
class Solution
{
    int partton(vector<int> &nums, int left, int right)
    {
        int idx = left + rand() % (right - left + 1);
        swap(nums[left], nums[idx]);
        int value = nums[left];
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= value)
                j--;           // 从右找 < value
            nums[i] = nums[j]; // 填坑
            while (i < j && nums[i] <= value)
                i++;           // 从左找 > value
            nums[j] = nums[i]; // 填坑
        }
        nums[i] = value;
        return i;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 使用二叉堆
        // priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆
        // for (auto num : nums)                                   // 遍历数组
        // {
        //     minHeap.push(num);      // 将元素加入小顶堆
        //     if (minHeap.size() > k) // 如果小顶堆的大小超过k，弹出堆顶元素
        //     {
        //         minHeap.pop();
        //     }
        // }
        // return minHeap.top(); // 返回小顶堆的堆顶元素，即第k个最大的元素

        // sort(nums.begin(), nums.end(), greater<int>());
        // return nums[k - 1];

        // 快速选择算法
        int n = nums.size();
        int target = n - k;
        int left = 0, right = nums.size() - 1;
        while (true)
        {
            int pos = partton(nums, left, right);
            if (pos == n - k)
            {

                return nums[pos];
            }
            else if (pos < n - k)
            {
                left = pos + 1;
            }
            else
            {
                right = pos - 1;
            }
        }
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
// [3,2,1,5,6,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,1,2,4,5,5,6]\n4\n
// @lcpr case=end

 */
