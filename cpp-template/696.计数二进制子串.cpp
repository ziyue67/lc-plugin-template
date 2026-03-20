/*
 * @lc app=leetcode.cn id=696 lang=cpp
 * @lcpr version=30400
 *
 * [696] 计数二进制子串
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
  int countBinarySubstrings(string s)
  {
    int pre = 0, cur = 1, answer = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i] == s[i - 1])
      {
        cur++;
      }
      else{
        answer += min(pre, cur);
        pre = cur;
        cur =1;
      }
       
    }
    answer += min(pre, cur);
    return answer;
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
// "00110011"\n
// @lcpr case=end

// @lcpr case=start
// "10101"\n
// @lcpr case=end

 */
