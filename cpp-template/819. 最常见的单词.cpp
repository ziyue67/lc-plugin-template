/*
 * @lc app=leetcode.cn id=819 lang=cpp
 * @lcpr version=30404
 *
 * [819] 最常见的单词
 *
 * https://leetcode.cn/problems/most-common-word/description/
 *
 * algorithms
 * Easy (45.98%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    75.1K
 * Total Submissions: 163.3K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]\n"a."\n[]'
 *
 * 给你一个字符串 paragraph 和一个表示禁用词的字符串数组 banned ，返回出现频率最高的非禁用词。题目数据 保证
 * 至少存在一个非禁用词，且答案 唯一 。
 *
 * paragraph 中的单词 不区分大小写 ，答案应以 小写 形式返回。
 *
 * 注意 单词不包含标点符号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.",
 * banned = ["hit"]
 * 输出："ball"
 * 解释：
 * "hit" 出现了 3 次，但它是禁用词。
 * "ball" 出现了两次（没有其他单词出现这么多次），因此它是段落中出现频率最高的非禁用词。
 * 请注意，段落中的单词不区分大小写，
 * 标点符号会被忽略（即使它们紧挨着单词，如 "ball,"），
 * 并且尽管 "hit" 出现的次数更多，但它不能作为答案，因为它是禁用词。
 *
 *
 * 示例 2：
 *
 * 输入：paragraph = "a.", banned = []
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= paragraph.length <= 1000
 * paragraph 由英文字母、空格 ' '、和以下符号组成："!?',;."
 * 0 <= banned.length <= 100
 * 1 <= banned[i].length <= 10
 * banned[i] 仅由小写英文字母组成
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cctype>
using namespace std;

// @lc code=start
class Solution
{
public:
    string
    mostCommonWord(string paragraph, vector<string> &banned)
    {
        // unordered_set<string> ban(banned.begin(), banned.end()); // 初始化禁用词集合
        // unordered_map<string, int> wordCount;                    // 用于统计单词出现次数的哈希表
        // for (auto &c : paragraph)                                // 遍历段落中的每个字符
        // {
        //     if (ispunct(c)) // 如果是标点符号
        //         c = ' ';    // 将其替换为空格
        //     else
        //         c = tolower(c); // 否则将其转换为小写字母
        // }

        // stringstream ss(paragraph); // 将段落转换为字符串流
        // string word;                // 用于存储当前单词
        // string word1, ans;          // 用于存储当前单词和最终答案
        // int maxCount = 0;           // 初始化最大出现次数为0
        // while (ss >> word)
        // {
        //     if (ban.count(word))
        //         continue;                // 如果当前单词是禁用词，则跳过
        //     int cur = ++wordCount[word]; // 统计当前单词出现次数
        //     if (cur > maxCount)
        //     {                   // 如果当前单词出现次数大于最大出现次数
        //         maxCount = cur; // 更新最大出现次数
        //         ans = word;     // 更新最终答案为当前单词
        //     }
        // }
        // return ans; // 返回出现频率最高的非禁用词

        // unordered_map<string, int> wordCount; // 用于统计单词出现次数的哈希表
        // string word;
        // for (char c : paragraph)
        // {
        //     if (isalpha(c))
        //     {
        //         word += tolower(c);
        //     }
        //     else if (!word.empty())
        //     {
        //         wordCount[word]++;
        //         word.clear();
        //     }
        // }
        // if (!word.empty())
        // {
        //     wordCount[word]++; // 别忘了最后一个
        // }
        // string ans;
        // int maxCount = 0;
        // for (auto &p : wordCount)
        // {
        //     string w = p.first;
        //     int cnt = p.second;

        //     bool isBanned = false;
        //     for (const string &b : banned)
        //     {
        //         if (w == b)
        //         {
        //             isBanned = true;
        //             break;
        //         }
        //     }
        //     if (!isBanned && cnt > maxCount)
        //     {
        //         maxCount = cnt;
        //         ans = w;
        //     }
        // }
        // return ans;

        unordered_map<string, bool> vis;
        for (auto &x : banned)
            vis[x] = true;
        string ans;
        int maxCount = 0;
        string t;
        unordered_map<string, int> Count;
        paragraph += ' ';
        for (char c : paragraph)
        {
            for (const auto &c : paragraph)
            {
                if (isalpha(c))
                {
                    t += tolower(c);
                }
                else
                {
                    if (!t.empty() && !vis[t] && ++Count[t] > maxCount)
                    {
                        maxCount = Count[t];
                        ans = t;
                    }
                    t.clear();
                }
            }
        }
        return ans;
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
// "Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]\n
// @lcpr case=end

// @lcpr case=start
// "a."\n[]\n
// @lcpr case=end

 */
