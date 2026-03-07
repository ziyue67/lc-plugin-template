/*
 * @lc app=leetcode.cn id=217 lang=cpp
 * @lcpr version=30400
 *
 * [217] 存在重复元素
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_map"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) {
        // 使用 unordered_set 存储已经遍历过的数字，利用哈希集合的 O(1) 查找特性
    unordered_set<int> set;

        // 遍历数组中的每个元素
        for (int i = 0; i < nums.size(); i++) {
            // 检查当前元素是否已经在集合中存在
            if (set.find(nums[i]) != set.end()) {
                // 如果存在，说明找到了重复元素，直接返回 true
        return true;
      }
            // 将当前元素插入到集合中，以便后续元素进行对比
      set.insert(nums[i]);
    }

        // 遍历完成未发现重复元素，返回 false
    return false;
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
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,3,3,4,3,2,4,2]\n
// @lcpr case=end

 */
