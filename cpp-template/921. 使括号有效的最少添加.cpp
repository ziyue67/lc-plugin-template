/*
 * @lc app=leetcode.cn id=921 lang=cpp
 * @lcpr version=30404
 *
 * [921] 使括号有效的最少添加
 *
 * https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (73.57%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    89.4K
 * Total Submissions: 121.6K
 * Testcase Example:  '"())"\n"((("'
 *
 * 只有满足下面几点之一，括号字符串才是有效的：
 *
 *
 * 它是一个空字符串，或者
 * 它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
 * 它可以被写作 (A)，其中 A 是有效字符串。
 *
 *
 * 给定一个括号字符串 s ，在每一次操作中，你都可以在字符串的任何位置插入一个括号
 *
 *
 * 例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 或结束括号为 "())))" 。
 *
 *
 * 返回 为使结果字符串 s 有效而必须添加的最少括号数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "())"
 * 输出：1
 *
 *
 * 示例 2：
 *
 * 输入：s = "((("
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 只包含 '(' 和 ')' 字符。
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "leetcode/editor/common/ListNode.cpp"
#include "leetcode/editor/common/TreeNode.cpp"
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                // 左括号入栈
                st.push(s[i]);
            }
            else
            {
                if (st.empty() || st.top() == ')')
                {                  // 如果栈为空或者栈顶是右括号，说明当前右括号没有匹配的左括号，需要添加一个左括号
                    st.push(s[i]); // 右括号入栈
                }
                else
                {
                    st.pop();// 如果栈顶是左括号，说明当前右括号有匹配的左括号，弹出栈顶的左括号
                }
            }
        }
        return st.size(); // 栈中剩余的括号就是需要添加的括号数
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
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "((("\n
// @lcpr case=end

 */
