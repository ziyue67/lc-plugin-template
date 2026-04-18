/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30403
 *
 * [383] 赎金信
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_map"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_multimap<char,int> m;// key-value
      for(auto c:magazine){  
        m.insert({c,1}); //这个是插入一个键值对，如果key已经存在，则value会自动+1
      }
      for(auto c:ransomNote){ //遍历ransomNote，如果ransomNote中的字符在magazine中存在，则删除该字符，否则返回false
        auto it=m.find(c); 
        if(it==m.end()){
          return false;
        }
        m.erase(it);
      }
      return true;

    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */

