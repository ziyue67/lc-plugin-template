/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30400
 *
 * [922] 按奇偶排序数组 II
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
  vector<int> sortArrayByParityII(vector<int> &nums)
  {
    // int i = 0, j = 1;
    // while(i<nums.size()&& j<nums.size()){
    //   while(i<nums.size()&&nums[i]%2==0){
    //     i+=2;
    //   }
    //   while(j<nums.size()&&nums[j]%2==1){
    //     j+=2;
    //   }
    //   if(i<nums.size()&&j<nums.size()){
    //     swap(nums[i],nums[j]);
    //   }

    // }
    // return nums;

    int i = 0, j = 1; // i指向偶数位，j指向奇数位
    while (i < nums.size() && j < nums.size())
    {
      if(nums[i]%2==0){ //偶数位是偶数
        i+=2;
      }
      else if(nums[j]%2==1){ //奇数位是奇数 
        j+=2;
      }
      else{
        swap(nums[i],nums[j]); //偶数位是奇数，奇数位是偶数，交换
      }
    }
    return nums;
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
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */
