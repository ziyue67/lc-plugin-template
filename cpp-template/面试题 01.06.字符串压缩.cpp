/*
 * @lc app=leetcode.cn id=面试题 01.06 lang=cpp
 * @lcpr version=30403
 *
 * [面试题 01.06] 字符串压缩
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string compressString(string S) {
      int i=0, j=0 ,n=S.size();
      string res;
      while(i<n){
         while(j <n && S[i]==S[j]) j++; //j指向下一个不同的字符
         res+=S[i]; //添加字符
         res+=to_string(j-i); //添加字符出现的次数
         i=j;
      }
      return res.size() < n ? res : S; //如果压缩后的字符串长度比原字符串短，则返回压缩后的字符串，否则返回原字符串
     


        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "aabcccccaa"\n
// @lcpr case=end

// @lcpr case=start
// "abbccd"\n
// @lcpr case=end

 */

