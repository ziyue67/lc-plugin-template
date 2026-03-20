/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30400
 *
 * [977] 有序数组的平方
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
  vector<int> sortedSquares(vector<int> &nums)
  {
    // int n = nums.size();
    // vector<int> ans(n);
    // int left = 0, right = n - 1; // 双指针
    // for (int i = n - 1; i >= 0; i--) // 倒序填充
    // {
    //   int temp = nums[left] * nums[left];  // 取绝对值
    //   int temp2 = nums[right] * nums[right]; // 取绝对值
    //   if (temp > temp2) // 左边大
    //   {
    //     ans[i] = temp; // 填充
    //     left++; // 左指针右移
    //   }
    //   else
    //   {
    //     ans[i] = temp2; // 填充
    //     right--; // 右指针左移
    //   }
    // }
    // return ans; // 返回结果

    int n = nums.size();
    vector<int> ans(n);
    int left = 0, right = n - 1; // 双指针
    for (int i = n - 1; i >= 0; i--) // 倒序填充
    {
      int x =nums[left] , y = nums[right];// 取绝对值
      if(-x > y) // 左边大
      {
        ans[i] = x * x; // 填充
        left++; // 左指针右移
      }
      else{
        ans[i] = y * y; // 填充
        right--; // 右指针左移
      }
    }
    

    return ans; // 返回结果
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
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
