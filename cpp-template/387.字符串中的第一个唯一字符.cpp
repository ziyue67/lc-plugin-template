/*
 * @lc app=leetcode.cn id=387 lang=cpp
 * @lcpr version=30403
 *
 * [387] 字符串中的第一个唯一字符
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
class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> map;
    for (auto c : s)
    {
      map[c]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
      if (map[s[i]] == 1)
      {
        return i;
      }
    }
    return -1;  
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
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "loveleetcode"\n
// @lcpr case=end

// @lcpr case=start
// "aabb"\n
// @lcpr case=end

 */
