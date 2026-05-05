/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30403
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "stack"
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
      stack<char>st;
      for(auto c:s){
        if(!st.empty()&&st.top()==c){
          st.pop();
        }
        else{
          st.push(c);
        }
      }
      string res="";
      while(!st.empty()){
        res+=st.top();
        st.pop();
      }
      reverse(res.begin(),res.end());
      return res;
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

// @lcpr case=start
// "azxxzy"\n
// @lcpr case=end

 */

