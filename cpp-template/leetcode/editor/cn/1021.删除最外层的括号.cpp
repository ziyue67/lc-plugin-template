/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 * @lcpr version=30404
 *
 * [1021] 删除最外层的括号
 *
 * https://leetcode.cn/problems/remove-outermost-parentheses/description/
 *
 * algorithms
 * Easy (82.15%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    120.1K
 * Total Submissions: 146.2K
 * Testcase Example:  '"(()())(())"\n"(()())(())(()(()))"\n"()()"'
 *
 * 有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。
 *
 *
 * 例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
 *
 *
 * 如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），其中 A 和 B
 * 都是非空有效括号字符串。
 *
 * 给出一个非空有效字符串 s，考虑将其进行原语化分解，使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
 *
 * 对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "(()())(())"
 * 输出："()()()"
 * 解释：
 * 输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
 * 删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
 *
 * 示例 2：
 *
 * 输入：s = "(()())(())(()(()))"
 * 输出："()()()()(())"
 * 解释：
 * 输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
 * 删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
 *
 *
 * 示例 3：
 *
 * 输入：s = "()()"
 * 输出：""
 * 解释：
 * 输入字符串为 "()()"，原语化分解得到 "()" + "()"，
 * 删除每个部分中的最外层括号后得到 "" + "" = ""。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 为 '(' 或 ')'
 * s 是一个有效括号字符串
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;
        string res;
        for (auto c : s)
        {
            if (c == '(') // 遇到左括号就匹配
            {
                if (!st.empty()) // 栈不为空     res += c;  // 说明不是最外层括号
                {
                    res += c;
                }
                st.push(c); // 入栈
            }
            else // 如果是右括号   res += c;  // 说明不是最外层括号
            {
                st.pop();
                if (!st.empty())
                {
                    res += c;
                }
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
// "(()())(())"\n
// @lcpr case=end

// @lcpr case=start
// "(()())(())(()(()))"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

 */
