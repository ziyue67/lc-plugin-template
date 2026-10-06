/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30404
 *
 * [704] 二分查找
 */

#include <iostream>
#include <vector>
#include <string>
#include "leetcode/editor/common/ListNode.cpp"
#include "leetcode/editor/common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  first =0,last=nums.size()-1;
        while(first<=last){
            int mind = last-first/2;
            if(nums[mind]==target){
                return mind;
            }
            else if(nums[mind]<target){
                first=mind+1;
            }
            else{
                last=mind-1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */

