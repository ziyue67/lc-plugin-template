/*
 * @lc app=leetcode.cn id=697 lang=cpp
 * @lcpr version=30403
 *
 * [697] 数组的度
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
  int findShortestSubArray(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int maxFreq = 0;
    for (const auto &num : nums)
    {
      mp[num]++;
      maxFreq = max(mp[num], maxFreq);
    }
    for (auto iter = mp.begin(); iter != mp.end();)
    {
      if (iter->second != maxFreq)
        iter = mp.erase(iter);
      else
        iter++;
    }

    int res = INT_MAX;
    for (const auto &m : mp)
    {
      int first = -1;
      int last = -1;
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == m.first)
        {
          if (first == -1)
            first = i;
          last = i;
        }
      }
      res = min(last - first + 1, res);
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
// [1,2,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,1,4,2]\n
// @lcpr case=end

 */
