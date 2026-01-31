/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30305
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), l=0,r=0;
        while(r<n){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
    }
};
// @lc code=end

// 辅助函数：打印数组
void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1: nums = [0,1,0,3,12]
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    cout << "测试用例1: ";
    printArray(nums1);
    cout << endl;
    
    // 测试用例2: nums = [0]
    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    cout << "测试用例2: ";
    printArray(nums2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

