/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 * @lcpr version=30402
 *
 * [2540] 最小公共值
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution
{
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> set1(nums1.begin(), nums1.end()); // 将nums1中的元素存入set1中
    for (auto &num : nums2) // 遍历nums2中的元素
    {
      if (set1.count(num)) // 如果set1中存在num，则返回num
      {
        return num;
      }
    }
    return -1; 
    
  }
};
// @lc code=end

int main()
{
  Solution s;
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {2, 4};
  cout << s.getCommon(nums1, nums2) << endl; // 输出2

  // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n[2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,6]\n[2,3,4,5]\n
// @lcpr case=end

 */
