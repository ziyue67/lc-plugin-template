/*
 * @lc app=leetcode.cn id=524 lang=cpp
 * @lcpr version=30403
 *
 * [524] 通过删除字母匹配到字典里最长单词
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
  bool isSub(string s, string t){ // 判断s是否包含t
    int i = 0, j = 0; // i指向s，j指向t
    while(i < s.size() && j < t.size()){ // 遍历s和t
      if(s[i] == t[j]){ // 如果s[i]等于t[j]，则i和j都向后移动一位
        j++;
      }
      i++; // s[i]不等于t[j]，则i向后移动一位
    }
    return j == t.size(); // 如果j等于t的长度，说明t是s的子串，返回true，否则返回false
  }
  string findLongestWord(string s, vector<string> &dictionary)
  {
    string res; // 存储结果
    for(auto &str : dictionary){  // 遍历字典中的每个字符串
       if(isSub(s,str) && (str.size() > res.size() || (str.size() == res.size() && str < res))){
        res = str;
       }
    }
    return res;
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
// "abpcplea"\n["ale","apple","monkey","plea"]\n
// @lcpr case=end

// @lcpr case=start
// "abpcplea"\n["a","b","c"]\n
// @lcpr case=end

 */
