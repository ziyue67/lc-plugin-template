/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30403
 *
 * [80] 删除有序数组中的重复项 II
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
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();  // 数组长度
    if (n <= 2)   // 数组长度小于等于2时，直接返回数组长度
      return n;
    int slow = 2, fast = 2; // 慢指针和快指针初始化为2
    while (fast < n)
    {
      if (nums[slow - 2] != nums[fast])
      {
        nums[slow++] = nums[fast];
      }
      fast++;
    }
    return slow;
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
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
