/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30400
 *
 * [219] 存在重复元素 II
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
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_map<int, int>map; // 使用哈希表存储最近出现元素的索引
    for (int i = 0; i < nums.size(); i++)
    {
      if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
      { // 如果当前元素在窗口内出现过，返回 true
        return true;
      }
      map[nums[i]] = i; // 更新或插入元素及其索引到哈希表
    }
    return false; // 遍历完未找到重复元素，返回 false
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
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
