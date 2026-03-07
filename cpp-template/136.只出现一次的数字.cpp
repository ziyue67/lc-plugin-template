/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=30400
 *
 * [136] 只出现一次的数字
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
  /**
   * @brief Finds the single number in an array where every other number appears twice.
   *
   * This function takes a vector of integers where every element appears twice except for one.
   * It returns the element that appears only once.
   * The implementation uses bitwise XOR to efficiently find the unique element.
   *
   * @param nums Reference to a vector of integers containing exactly one unique element and all others appearing twice.
   * @return The integer that appears only once in the array.
   */
  int singleNumber(vector<int> &nums)
  {
    int res = 0;
    // 利用异或运算找出只出现一次的数字
    for (int i = 0; i < nums.size(); i++)
    {
      res ^= nums[i]; // 异或运算，相同为0，不同为1
    }
    return res; // 返回只出现一次的数字
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
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
