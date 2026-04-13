/*
 * @lc app=leetcode.cn id=457 lang=cpp
 * @lcpr version=30403
 *
 * [457] 环形数组是否存在循环
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
  bool circularArrayLoop(vector<int> &nums)
  {
    // int n = nums.size();
    // auto next = [&](int i) -> int
    // {
    //   return (i + nums[i] + n) % n;
    // };
    // for (int i = 0; i < n; i++)
    // {
    //   if (nums[i] == 0)
    //     continue;
    //   int slow = i, fast = next(i);
    //   while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0)
    //   {
    //     if (slow == fast)
    //     {
    //       if (slow == next(slow))
    //         break;
    //       return true;
    //     }
    //     slow = next(slow);
    //     fast = next(next(fast));
    //   }
    // }
    // return false;
    int n = nums.size();
    auto getNext = [&](int i) -> int
    {
      return (i + nums[i] % n + n) % n;
    };
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
        continue;
      int cur = i;
      unordered_set<int> visited;
      int sign = nums[i] > 0 ? 1 : -1;
      while (true)
      {
        if (nums[cur] == 0 || nums[cur] * sign < 0)
          break;
        if (visited.count(cur))
          return true;
        if (getNext(cur) == cur)
          break;
        visited.insert(cur);
        cur = getNext(cur);
      }
    }
    return false;
  }
};
// @lc code=end

int main()
{
  Solution solution;
  // your test code here
  return 0;
}

  /*
  // @lcpr case=start
  // [2,-1,1,2,2]\n
  // @lcpr case=end

  // @lcpr case=start
  // [-1,-2,-3,-4,-5,6]\n
  // @lcpr case=end

  // @lcpr case=start
  // [1,-1,5,1,4]\n
  // @lcpr case=end

   */
