/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30400
 *
 * [31] 下一个排列
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size(); // 从后往前找第一个升序的数
      int i=n-2; // 从倒数第二个开始 
      for(;i>=0;i--){
        if(nums[i]<nums[i+1]){ // 找到后 break
          break;
        }

      }
      if(i>=0){
        int j=n-1; // 从后往前找第一个大于nums[i]的数
        for(;j>=0;j--){
          if(nums[j]>nums[i]){ // 找到后交换
            break;
          }
        }
        swap(nums[i],nums[j]);
      }
      reverse(nums.begin()+i+1,nums.end()); // 反转i+1到末尾的数
    }

};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

