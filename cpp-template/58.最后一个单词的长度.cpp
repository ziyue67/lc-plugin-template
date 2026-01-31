/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30305
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode.cn/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (48.50%)
 * Likes:    792
 * Dislikes: 0
 * Total Accepted:    757.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '"Hello World"\n"   fly me   to   the moon  "\n"luffy is still joyboy"'
 *
 * 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
 *
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "Hello World"
 * 输出：5
 * 解释：最后一个单词是“World”，长度为 5。
 *
 *
 * 示例 2：
 *
 * 输入：s = "   fly me   to   the moon  "
 * 输出：4
 * 解释：最后一个单词是“moon”，长度为 4。
 *
 *
 * 示例 3：
 *
 * 输入：s = "luffy is still joyboy"
 * 输出：6
 * 解释：最后一个单词是长度为 6 的“joyboy”。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅有英文字母和空格 ' ' 组成
 * s 中至少存在一个单词
 *
 *
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
    int lengthOfLastWord(string s)
    {
        int i = s.length() - 1; // i 指向字符串最后一个字符的索引
        while (s[i] == ' ') // 从后往前遍历，直到遇到第一个非空格字符 为止  
        {    
            i--; // 跳过末尾的所有空格
       }
       int j = i;               // j 指向最后一个单词的最后一个字符的索引  从0开始的下标访问要-1
       while(j>=0&&s[j] !=' '){ // 从后往前遍历，直到遇到第一个空格字符为止
        j--; // 跳过最后一个单词的所有字符
       }
       return i - j; // 返回最后一个单词的长度   单词长度 = 末尾索引 - 起始前一个位置
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    cout << "测试用例1: " << solution.lengthOfLastWord("Hello World") << endl;
    cout << "测试用例2: " << solution.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << "测试用例3: " << solution.lengthOfLastWord("luffy is still joyboy") << endl;
    
    return 0;
}

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
