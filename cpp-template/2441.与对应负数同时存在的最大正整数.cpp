/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 * @lcpr version=30402
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"

using namespace std;

// @lc code=start
class Solution
{
public:
  int findMaxK(vector<int> &nums)
  {
    unordered_set<int> s; 
    int res=-1; //初始化为-1，因为题目要求返回正整数
    for (auto i : nums)
    {
      if (s.count(-i)) 
      {
        res=max(res,abs(i));  //abs()取绝对值
      }
      s.insert(i);  //将i插入到set中
      
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
// [-1,2,-3,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,10,6,7,-7,1]\n
// @lcpr case=end

// @lcpr case=start
// [-10,8,6,7,-2,-3]\n
// @lcpr case=end

 */
