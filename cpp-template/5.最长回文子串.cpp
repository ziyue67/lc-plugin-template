/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30307
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (40.27%)
 * Likes:    7970
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 5.6M
 * Testcase Example:  '"babad"\n"cbbd"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
       int ans_L=0,ans_R=0;
       for(int i=0;i<2*n-1;i++){
        int l=i/2,r=(i+1)/2;
        while (l>=0 && r<n &&s[l]==s[r])
        {
            l--;
            r++;
        }
        if(r-l-1>ans_R-ans_L){
            ans_L=l+1;
            ans_R=r;
        }
        
       } 
       return s.substr(ans_L,ans_R-ans_L);
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<pair<string,string>> tests = {
        {"babad", "bab or aba"},
        {"cbbd", "bb"},
        {"a", "a"},
        {"ac", "a or c"},
    };

    for (auto &tc : tests) {
        const string &s = tc.first;
        string out = solution.longestPalindrome(s);
        cout << "input: \"" << s << "\" -> output: \"" << out << "\"; expected: " << tc.second << "\n";
    }

    return 0;
}



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

