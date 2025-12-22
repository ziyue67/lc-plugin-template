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

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

