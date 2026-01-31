/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30305
 *
 * [75] 颜色分类
 *
 * https://leetcode.cn/problems/sort-colors/description/
 *
 * algorithms
 * Medium (63.38%)
 * Likes:    2024
 * Dislikes: 0
 * Total Accepted:    895.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,0,2,1,1,0]\n[2,0,1]'
 *
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
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
    void sortColors(vector<int>& nums) {
        // 初始化指针：fast 用于遍历数组，slow 用于标记0的位置，end 用于标记2的位置
        int *fast = &nums[0];
        int *slow = &nums[0];
        int *end = &nums[nums.size() - 1];
        // 当fast指针没有超过end指针时，继续循环
        while (fast <= end) {
            // 如果当前元素是0，与slow位置交换，并移动slow和fast
            if (*fast == 0) {
            swap(*fast, *slow);
            slow++;
            fast++;
            }
            // 如果当前元素是1，只移动fast
            else if (*fast == 1) {
            fast++;
            }
            // 如果当前元素是2，与end位置交换，并移动end
            else {
            swap(*fast, *end);
            end--;
            }
        }
            
        }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 测试用例1: nums = [2,0,2,1,1,0]
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums1);
    cout << "测试用例1: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // 测试用例2: nums = [2,0,1]
    vector<int> nums2 = {2, 0, 1};
    solution.sortColors(nums2);
    cout << "测试用例2: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

