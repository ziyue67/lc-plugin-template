/*
 * @lc app=leetcode.cn id=443 lang=cpp
 * @lcpr version=30403
 *
 * [443] 压缩字符串
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int w=0, s = 0;
    for(int r=0;r<chars.size();r++){
      if(r+1==chars.size()||chars[r]!=chars[r+1]){
        chars[w++]=chars[r];
        if(r>s){
          auto count =to_string(r-s+1); //计数
          for(auto c:count){
            chars[w++]=c;
          }
        }
        s=r+1;
      }
    }
    return w;
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
// ["a","a","b","b","c","c","c"]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]\n
// @lcpr case=end

 */
