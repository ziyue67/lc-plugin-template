/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30403
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
      stack<char>stk;
      for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
          stk.push(c);
        }
        else {
          if(stk.empty()) return false;
          char top = stk.top();
          stk.pop();
          if (c == ')' && top != '(') return false;
          if (c == ']' && top != '[') return false;
          if (c == '}' && top != '{') return false;
        }
      }
      return stk.empty();
        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

