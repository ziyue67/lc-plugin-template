/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30403
 *
 * [189] 轮转数组
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    k %= nums.size(); // 防止k大于数组长度
    reverse(nums.begin(), nums.end()); // 先将整个数组翻转
    reverse(nums.begin(), nums.begin() + k); // 翻转前k个元素
    reverse(nums.begin() + k, nums.end()); // 翻转剩余的元素
 
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
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
