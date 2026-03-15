/*
 * @lc app=leetcode.cn id=905 lang=cpp
 * @lcpr version=30400
 *
 * [905] 按奇偶排序数组
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
  vector<int> sortArrayByParity(vector<int> &nums)
  {
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
      while (left < right && nums[left] % 2 == 0)
        left++;
      while (left < right && nums[right] % 2 == 1)
        right--;
      if (left < right)
      {
        swap(nums[left], nums[right]);
      }
    }
    return nums;
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
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
