/*
 * @lc app=leetcode.cn id=LCR 139 lang=cpp
 * @lcpr version=30401
 *
 * [LCR 139] 训练计划 I
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
    vector<int> trainingPlan(vector<int>& actions) {
      int left=0,right=actions.size()-1; //双指针
      while(left<right){ //当left<right时，循环
        while(left<right &&actions[left] %2==1){ //当left<right时，且actions[left]为奇数时，left++
          left++;
        }
        while(left<right &&actions[right] %2==0){ //当left<right时，且actions[right]为偶数时，right--
          right--;
        }
        if(left<right){ //当left<right时，交换actions[left]和actions[right]
          swap(actions[left],actions[right]);
          left++;
          right--;
        }
      }
      return actions; //返回actions
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

