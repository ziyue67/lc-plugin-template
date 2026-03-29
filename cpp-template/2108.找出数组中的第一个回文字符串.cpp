/*
 * @lc app=leetcode.cn id=2108 lang=cpp
 * @lcpr version=30401
 *
 * [2108] 找出数组中的第一个回文字符串
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
    string firstPalindrome(vector<string>& words) {
      for(auto &words:words){ //auto &words:words  auto words:words
        string temp=words; //string temp=words;
        reverse(temp.begin(),temp.end()); //reverse(words.begin(),words.end());
        if(temp==words){ 
          return words; 
        }
      }
      return "";
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// ["abc","car","ada","racecar","cool"]\n
// @lcpr case=end

// @lcpr case=start
// ["notapalindrome","racecar"]\n
// @lcpr case=end

// @lcpr case=start
// ["def","ghi"]\n
// @lcpr case=end

 */

