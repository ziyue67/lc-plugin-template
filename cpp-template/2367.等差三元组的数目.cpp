/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 * @lcpr version=30401
 *
 * [2367] 等差三元组的数目
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
  int arithmeticTriplets(vector<int> &nums, int diff)
  {
    int ans = 0;  // 等差三元组的数目
    unordered_set<int>s; // 存储数组中的元素
    for(int x :nums){ // 遍历数组中的元素
      if(s.count(x-diff)&& s.count(x-diff *2)){ // 如果存在两个差为diff的元素
        ++ans; // 等差三元组的数目加1
      }
      s.insert(x); // 将当前元素插入到集合中
    }
    return ans; // 返回等差三元组的数目
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
// [0,1,4,6,7,10]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,8,9]\n2\n
// @lcpr case=end

 */
