/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=30401
 *
 * [1768] 交替合并字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string res; // 存储合并后的字符串
    int i=0,j=0; // 分别指向word1和word2的起始位置
    while(i <word1.size() || j<word2.size()){ // 当word1和word2都没有遍历完时
      if(i<word1.size()){
        res+=word1[i++]; // 将word1的当前字符添加到res中，并将i向后移动一位
      }
      if(j<word2.size()){
        res+=word2[j++]; // 将word2的当前字符添加到res中，并将j向后移动一位
      }

    }
    return res;
  }
};
// @lc code=end

int main()
{
  Solution solution;
  cout << solution.mergeAlternately("abc", "pqr") << endl; // apbqcr
  cout << solution.mergeAlternately("ab", "pqrs") << endl; // apbqrs
  cout << solution.mergeAlternately("abcd", "pq") << endl;  // apbqcd
}

/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */
