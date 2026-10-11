/*
 * @lc app=leetcode.cn id=500 lang=cpp
 * @lcpr version=30404
 *
 * [500] 键盘行
 *
 * https://leetcode.cn/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (74.06%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    89.9K
 * Total Submissions: 121.4K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]\n["omk"]\n["adsdf","sfd"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 *
 * 请注意，字符串 不区分大小写，相同字母的大小写形式都被视为在同一行。
 *
 * 美式键盘 中：
 *
 *
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 *
 * 输出：["Alaska","Dad"]
 *
 * 解释：
 *
 * 由于不区分大小写，"a" 和 "A" 都在美式键盘的第二行。
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["omk"]
 *
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：words = ["adsdf","sfd"]
 *
 * 输出：["adsdf","sfd"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] 由英文字母（小写和大写字母）组成
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_map<char, int> rowMap;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        for (char c : row1)
        {
            rowMap[c] = 1;
            rowMap[tolower(c)] = 1;
        }
        for (char c : row2)
        {
            rowMap[c] = 2;
            rowMap[tolower(c)] = 2;
        }
        for (char c : row3)
        {
            rowMap[c] = 3;
            rowMap[tolower(c)] = 3;
        }
        vector<string> res;
        for (const string &word : words)
        {
            int row = rowMap[tolower(word[0])];
            bool isSameRow = true;
            for (char c : word)
            {
                if (rowMap[tolower(c)] != row)
                {
                    isSameRow = false;
                    break;
                }
            }
            if (isSameRow)
                res.push_back(word);
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
// ["Hello","Alaska","Dad","Peace"]\n
// @lcpr case=end

// @lcpr case=start
// ["omk"]\n
// @lcpr case=end

// @lcpr case=start
// ["adsdf","sfd"]\n
// @lcpr case=end

 */
