/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30305
 *
 * [1] 两数之和
 *
 * https://leetcode.cn/problems/two-sum/description/
 *
 * algorithms
 * Easy (55.06%)
 * Likes:    20459
 * Dislikes: 0
 * Total Accepted:    7M
 * Total Submissions: 12.7M
 * Testcase Example:  '[2,7,11,15]\n9\n[3,2,4]\n6\n[3,3]\n6'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案
 * 
 * 
 * 
 * 
 * 进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 测试用例 1: nums = [2,7,11,15], target = 9
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = solution.twoSum(nums1, target1);
    cout << "测试用例 1: nums = [2,7,11,15], target = 9" << endl;
    cout << "输出: [" << res1[0] << "," << res1[1] << "]" << endl << endl;
    
    // 测试用例 2: nums = [3,2,4], target = 6
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = solution.twoSum(nums2, target2);
    cout << "测试用例 2: nums = [3,2,4], target = 6" << endl;
    cout << "输出: [" << res2[0] << "," << res2[1] << "]" << endl << endl;
    
    // 测试用例 3: nums = [3,3], target = 6
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = solution.twoSum(nums3, target3);
    cout << "测试用例 3: nums = [3,3], target = 6" << endl;
    cout << "输出: [" << res3[0] << "," << res3[1] << "]" << endl << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

