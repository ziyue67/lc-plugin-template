/*
 * @lc app=leetcode.cn id=LCR 182 lang=cpp
 * @lcpr version=30403
 *
 * [LCR 182] 动态口令
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
    string dynamicPassword(string password, int target) {
      // if(password.size()==0) return password;  //空字符串直接返回
      // string s=password.substr(0,target); //截取前target个字符
      // string res=password.substr(target,password.size()-target);  //截取target到末尾的字符
      // return res+s;  //将截取的字符拼接起来
      return password.substr(target,password.size()-target) + password.substr(0,target);  //直接拼接
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "s3cur1tyC0d3"\n4\n
// @lcpr case=end

// @lcpr case=start
// "vbzkgsaoiu"\n2\n
// @lcpr case=end

 */

