/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 * @lcpr version=30401
 *
 * [2000] 反转单词前缀
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
  string reversePrefix(string word, char ch)
  {
    int i = 0;  //从第一个字符开始遍历 
    for (; i < word.size(); i++) 
    {
      if (word[i] == ch) //找到第一个等于ch的字符
      {
        break; 
      }
      if(i== word.size()-1) //如果遍历到末尾都没有找到ch，则返回原字符串
      {
        return word;
      }
    }
    reverse(word.begin(),word.begin()+i+1); //注意这里要加1，因为i是从0开始的
    return word;
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
// "abcdefd"\n"d"\n
// @lcpr case=end

// @lcpr case=start
// "xyxzxe"\n"z"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"z"\n
// @lcpr case=end

 */
