/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 * @lcpr version=30305
 *
 * [1456] 定长子串中元音的最大数目
 *
 * https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (61.65%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    144.8K
 * Total Submissions: 234.7K
 * Testcase Example:  '"abciiidef"\n3\n"aeiou"\n2\n"leetcode"\n3'
 *
 * 给你字符串 s 和整数 k 。
 * 
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 
 * 英文中的 元音字母 为（a, e, i, o, u）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abciiidef", k = 3
 * 输出：3
 * 解释：子字符串 "iii" 包含 3 个元音字母。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aeiou", k = 2
 * 输出：2
 * 解释：任意长度为 2 的子字符串都包含 2 个元音字母。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "leetcode", k = 3
 * 输出：2
 * 解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "rhythms", k = 4
 * 输出：0
 * 解释：字符串 s 中不含任何元音字母。
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = "tryhard", k = 4
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 * 1 <= k <= s.length
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
using namespace std;

// @lc code=start
class Solution {
public:
    // 计算字符串 s 中长度为 k 的子串中元音的最大数目
    int maxVowels(string s, int k) {
        // 定义元音字母集合
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        // 初始化最大值和当前窗口元音数
        int ans = 0, sum = 0;
        // 获取字符串长度
        int n = s.size();
        // 使用滑动窗口遍历字符串
        for (int r = 0; r < n; r++) {
            // 如果当前字符是元音，增加计数
            if (vowels.count(s[r])) {
                sum++;
            }
            // 如果窗口大小超过 k，移除左边字符的影响
            if (r >= k && vowels.count(s[r - k])) {
                sum--;
            }
            // 更新最大值
            ans = max(ans, sum);
        }
        // 返回结果
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

 */

