/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * @lcpr version=30404
 *
 * [268] 丢失的数字
 *
 * https://leetcode.cn/problems/missing-number/description/
 *
 * algorithms
 * Easy (68.22%)
 * Likes:    930
 * Dislikes: 0
 * Total Accepted:    424.7K
 * Total Submissions: 622.6K
 * Testcase Example:  '[3,0,1]\n[0,1]\n[9,6,4,2,3,5,7,0,1]'
 *
 * 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,0,1]
 *
 * 输出：2
 *
 * 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 *
 * 输出：2
 *
 * 解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [9,6,4,2,3,5,7,0,1]
 *
 * 输出：8
 *
 * 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * nums 中的所有数字都 独一无二
 *
 *
 *
 *
 * 进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "leetcode/editor/common/ListNode.cpp"
#include "leetcode/editor/common/TreeNode.cpp"
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_map<int, bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] ==true; // 将数组中的数字存入哈希表
        }
        for(int i=0;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){// 如果哈希表中没有找到该数字，说明该数字就是缺失的数字
                return i;
            }
        }
        return -1;
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
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */
