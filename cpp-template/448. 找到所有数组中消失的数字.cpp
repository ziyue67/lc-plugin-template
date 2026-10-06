/*
 * @lc app=leetcode.cn id=448 lang=cpp
 * @lcpr version=30404
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.57%)
 * Likes:    1443
 * Dislikes: 0
 * Total Accepted:    406.9K
 * Total Submissions: 620.5K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]\n[1,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums
 * 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。
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
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         // O(n) 时间复杂度，O(1) 空间复杂度
        // unordered_map<int ,bool>mp;
        // vector<int>res;
        // for(auto i:nums){
        //     mp[i]=true;// 将数组中的数字存入哈希表
        // }
        // for(int i=1;i<nums.size()+1;i++){  
        //     if(mp.find(i)==mp.end()){
        //         res.push_back(i);// 如果哈希表中没有找到该数字，说明该数字就是缺失的数字
        //     }
        // }
        // return res;

        // O(n) 时间复杂度，O(1) 空间复杂度
        for(auto num:nums){
            int index=abs(num)-1;
            if(nums[index]>=0){
                nums[index]*=-1;
            }
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [4,3,2,7,8,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

