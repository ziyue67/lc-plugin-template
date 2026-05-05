/*
 * @lc app=leetcode.cn id=575 lang=cpp
 * @lcpr version=30403
 *
 * [575] 分糖果
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution {
public:
    // 1. 每个孩子最多只能给一个糖果。
    // 2. 对应每个孩子，他们的糖果数必须按照他们的评分从低到高排序，每个孩子的评分可能相同，因此孩子间评分相同的，糖果数也相同。
    // 3. 每个孩子至少分配一个糖果。
    
    int distributeCandies(vector<int>& candyType) {
      unordered_map<int, int> map;
      int res;
      for (int i = 0; i < candyType.size(); i++) {
        map[candyType[i]]++;
      }
      res = map.size() < candyType.size() / 2 ? map.size() : candyType.size() / 2;  // 糖果数最多为糖果种类的一半
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
// [1,1,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6,6]\n
// @lcpr case=end

 */

