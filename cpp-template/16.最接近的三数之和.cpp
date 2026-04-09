/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=30402
 *
 * [16] 最接近的三数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // 初始化 res 为前三个数的和
    int res = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; ++i)
    {
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        int sum = nums[i] + nums[l] + nums[r];

        if (abs(sum - target) < abs(res - target))
        {
          res = sum;
        }

        if (sum < target)
        {
          l++;
        }
        else if (sum > target)
        {
          r--;
        }
        else
        {
          return sum;
        }
      }
    }

    return res;
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
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */
