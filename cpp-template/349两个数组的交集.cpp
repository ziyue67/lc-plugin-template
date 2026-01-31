/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30305
 *
 * [349] 两个数组的交集
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(),nums1.end());//将nums1中的元素放入set1中
        vector<int>res;//存放结果
        for(int i:nums2){//遍历nums2
            if(set1.find(i)!=set1.end()){//如果set1中存在i
                res.push_back(i);//将i放入结果中
                set1.erase(i);//从set1中删除i
            }
        }
        return res;//返回结果
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
    
    // 测试用例1: nums1 = [1,2,2,1], nums2 = [2,2]
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res1 = solution.intersection(nums1, nums2);
    cout << "测试用例1: ";
    printArray(res1);
    cout << endl;
    
    // 测试用例2: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> res2 = solution.intersection(nums3, nums4);
    cout << "测试用例2: ";
    printArray(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

