/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30305
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    3432
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.6M
 * Testcase Example:  '["flower","flow","flight"]\n["dog","racecar","car"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 如果非空，则仅由小写英文字母组成
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
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string s0=strs[0]; //取第一个字符串作为参考
        // for(int i=0;i<s0.size();i++){ //遍历第一个字符串的每个字符
        //     for(int j=1;j<strs.size();j++){ //遍历其他字符串
        //         if(i>=strs[j].size()||s0[i]!=strs[j][i]){ //如果当前字符超过了其他字符串的长度，或者当前字符不相等
        //             return s0.substr(0,i); //返回公共前缀
        //         }
        //     }
        // }
        // return s0;
        string &s0 = strs[0];
        for (int j = 0; j < s0.size(); j++)
        { // 从左到右
            for (string &s : strs)
            { // 从上到下
                if (j == s.size() || s[j] != s0[j])
                {                           // 这一列有字母缺失或者不同
                    return s0.substr(0, j); // 0 到 j-1 是公共前缀
                }
            }
        }
        return s0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

