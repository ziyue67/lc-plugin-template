/*
 * @lc app=leetcode.cn id=2465 lang=cpp
 * @lcpr version=30402
 *
 * [2465] 不同的平均值数目
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
  int distinctAverages(vector<int> &nums)
  {
    unordered_set<double> s;        // 使用 set 存储所有不同的平均值
    sort(nums.begin(), nums.end()); // 先排序，便于双指针配对
    int i = 0, j = nums.size() - 1; // i 指向前最小，j 指向最大

    while (i < j)
    {
      // 每次将最小和最大配对，计算它们的平均值
      s.insert((double)(nums[i] + nums[j]) / 2);
      i++; // 移动左指针向右
      j--; // 移动右指针向左
    }

    return s.size(); // 返回不同平均值的个数
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
// [4,1,4,0,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,100]\n
// @lcpr case=end

 */
