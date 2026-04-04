/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 * @lcpr version=30402
 *
 * [2562] 找出数组的串联值
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
    long long findTheArrayConcVal(vector<int>& nums) {
      if(nums.empty()) return 0;
      long long res = 0;
      int left = 0, right = nums.size() - 1;
      while(left < right) {
        res +=stoi(to_string(nums[left]) + to_string(nums[right]));  //stoi将字符串转换为整数
        left++;
        right--;
      }
      if(left == right) res += nums[left];
      return res;

        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [7,52,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,14,13,8,12]\n
// @lcpr case=end

 */

