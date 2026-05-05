/*
 * @lc app=leetcode.cn id=645 lang=cpp
 * @lcpr version=30403
 *
 * [645] 错误的集合
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    unordered_map<int, int> map;
    for (auto &num : nums)
    {
      map[num]++;
    }
    int duplicate = 0, missing = 0; // duplicate=重复的数字 missing=缺失的数字
    for (int i = 1; i <= nums.size(); i++)
    {
      if (map[i] == 2) // 如果数字i出现了两次，说明它是重复的
      {
        duplicate = i; // 更新重复的数字
      }
      else if (map[i] == 0) // 如果数字i没有出现过，说明它是缺失的
      {
        missing = i; // 更新缺失的数字
      }
    }
    return {duplicate, missing}; // 返回重复的数字和缺失的数字
  }
};
// @lc code=end

int main()
{
  Solution solution;

  // Test case 1: [1,2,2,4] -> duplicate=2, missing=3
  vector<int> nums1 = {1, 2, 2, 4};
  vector<int> res1 = solution.findErrorNums(nums1);
  cout << "[" << res1[0] << "," << res1[1] << "]" << endl;

  // Test case 2: [1,1] -> duplicate=1, missing=2
  vector<int> nums2 = {1, 1};
  vector<int> res2 = solution.findErrorNums(nums2);
  cout << "[" << res2[0] << "," << res2[1] << "]" << endl;

  return 0;
}

/*
// @lcpr case=start
// [1,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
