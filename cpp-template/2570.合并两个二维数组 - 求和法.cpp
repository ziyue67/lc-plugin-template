/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 * @lcpr version=30402
 *
 * [2570] 合并两个二维数组 - 求和法
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "map"
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
  {
    // vector<vector<int>>res;
    // int i=0,j=0;
    // while(i<nums1.size()&&j<nums2.size()){
    //   if(nums1[i][0]==nums2[j][0]){
    //     res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
    //     i++;
    //     j++;
    //   }
    //   else if(nums1[i][0]<nums2[j][0]){
    //     res.push_back(nums1[i]);
    //     i++;
    //   }
    //   else{
    //     res.push_back(nums2[j]);
    //     j++;
    //   }
    // }
    // while(i<nums1.size()){
    //   res.push_back(nums1[i]);
    //   i++;
    // }
    // while(j<nums2.size()){
    //   res.push_back(nums2[j]);
    //   j++;
    // }
    // return res;
    map<int, int> mp; // key: id, value: sum
    for (auto &v : nums1)  // nums1[i][0] nums1[i][1]
      mp[v[0]] += v[1]; // mp[nums1[i][0]] += nums1[i][1]
    for (auto &v : nums2) // nums2[i][0] nums2[i][1]
      mp[v[0]] += v[1]; // mp[nums2[i][0]] += nums2[i][1]
    vector<vector<int>> res;  // res[i][0] res[i][1]
    for (auto &[id, val] : mp) // id: mp[i][0] val: mp[i][1]
      res.push_back({id, val}); // res.push_back({mp[i][0], mp[i][1]})
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
// [[1,2],[2,3],[4,5]]\n[[1,4],[3,2],[4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[3,6],[5,5]]\n[[1,3],[4,3]]\n
// @lcpr case=end

 */
