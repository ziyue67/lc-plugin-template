/*
 * @lc app=leetcode.cn id=287 lang=cpp
 * @lcpr version=30305
 *
 * [287] 寻找重复数
 *
 * https://leetcode.cn/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (67.13%)
 * Likes:    2715
 * Dislikes: 0
 * Total Accepted:    582.2K
 * Total Submissions: 867.3K
 * Testcase Example:  '[1,3,4,2,2]\n[3,1,3,4,2]\n[3,3,3,3,3]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
 * 
 * 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
 * 
 * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,4,2,2]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,3,4,2]
 * 输出：3
 * 
 * 
 * 示例 3 :
 * 
 * 输入：nums = [3,3,3,3,3]
 * 输出：3
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如何证明 nums 中至少存在一个重复的数字?
 * 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
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
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 初始化慢指针为数组第一个元素的值
        int slow = nums[0];
        // 初始化快指针为数组中慢指针值对应的元素的值
        int fast = nums[nums[0]];
        // 使用快慢指针找到环中的相遇点
        while (slow != fast)
        {
            // 慢指针每次移动一步
            slow = nums[slow];
            // 快指针每次移动两步
            fast = nums[nums[fast]];
        }
        // 将慢指针重置为0（数组起始索引）
        slow = 0;
        // 再次使用快慢指针找到环的入口，即重复的数字
        while (slow != fast) {
            // 慢指针每次移动一步
            slow = nums[slow];
            // 快指针每次移动一步
            fast = nums[fast];
        }
        // 返回重复的数字
        return slow;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */

