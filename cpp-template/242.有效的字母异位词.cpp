/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30403
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
        return false;
      unordered_map<char,int>map;
      for(auto c:s){  // unordered_map的find函数，如果没找到，返回的是end()
        map[c]++;  // 如果没找到，会自动创建一个键值对，值为0，然后++，所以不会报错
      }
      for(auto c:t){
        if(map.find(c)==map.end())
          return false;
        map[c]--;
        if(map[c] < 0)
          return false;
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
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

