/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30404
 *
 * [150] 逆波兰表达式求值
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "stack"
using namespace std;

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (token == "+")
                    s.push(a + b);
                else if (token == "-")
                    s.push(a - b);
                else if (token == "*")
                    s.push(a * b);
                else
                    s.push(a / b);
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
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
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
