/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30404
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (47.05%)
 * Likes:    3317
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8\n[5,7,7,8,8,10]\n6\n[]\n0'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
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
    vector<int> searchRange(vector<int>& nums, int target) {
        // int first = 0, last = nums.size() - 1;
        // while (first <= last)
        // {
        //     int mind = first + (last - first) / 2;
        //     if (nums[mind] == target)
        //     {
        //         int left=mind ,right=mind;
        //         while(left>=0 &&nums[left]==target){
        //             left--;
        //         }
        //         while(right<nums.size() && nums[right]==target){
        //             right++;
        //         }
        //         return {left+1,right-1};
        //     }
        //     else if (nums[mind] < target)
        //     {
        //         first = mind + 1;
        //     }
        //     else
        //     {
        //         last = mind - 1;
        //     }
        // }
        // return {-1, -1};
        int start = lower_bound(nums, target);
        // 没找到 target
        if (start == (int)nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        // target+1 的左边界减 1，就是 target 的右边界
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }

private:
    // 返回第一个 >= target 的下标（闭区间写法）
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1; // 向左边收缩
            }
            else
            {
                left = mid + 1;
            }
        }
        return left; // 循环结束时 left 就是第一个 >= target 的位置
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

