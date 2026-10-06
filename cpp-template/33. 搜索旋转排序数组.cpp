/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30404
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (46.53%)
 * Likes:    3464
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0\n[4,5,6,7,0,1,2]\n3\n[1]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为 [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始
 * 计数）。例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "leetcode/editor/common/ListNode.cpp"
#include "leetcode/editor/common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size() - 1;
        while (first <= last)
        {
            int mind = first + (last - first) / 2;
            if (nums[mind] == target)
            {
                return mind;
            }
            // 左边有序
            else if (nums[first] <= nums[mind])
            {
                if (nums[first] <= target && target < nums[mind])
                {
                    last = mind - 1;
                }
                else
                {
                    first = mind + 1;
                }
            }
            // 右边有序
            else
            {
                if (nums[mind] < target && target <= nums[last])
                {
                    first = mind + 1;
                }
                else
                {
                    last = mind - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

