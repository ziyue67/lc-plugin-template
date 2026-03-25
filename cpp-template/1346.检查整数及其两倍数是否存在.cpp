/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 * @lcpr version=30401
 *
 * [1346] 检查整数及其两倍数是否存在
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set; //记录已经遍历过的元素
       for(auto it:arr){ //遍历数组
          if(set.count(it*2) || (it %2 ==0 &&set.count(it/2))){ //如果当前元素的两倍或者一半在set中，说明存在，返回true
              return true;
          }
          set.insert(it); //将当前元素插入set中
       }
       return false;
        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [10,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,7,11]\n
// @lcpr case=end

 */

