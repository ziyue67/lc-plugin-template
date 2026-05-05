/*
 * @lc app=leetcode.cn id=389 lang=cpp
 * @lcpr version=30403
 *
 * [389] 找不同
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
    char findTheDifference(string s, string t) {
      unordered_map<char,int>map;
      for(char c:s){
        map[c]++;
      }
      for (int i = 0; i < t.size(); i++)
      {
        map[t[i]]--;
      }
      for (int i = 0; i < t.size(); i++)
      {
        if (map[t[i]] == -1)
        {
          return t[i];
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
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */

