/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=30305
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (53.08%)
 * Likes:    1210
 * Dislikes: 0
 * Total Accepted:    621.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abc"\n"ahbgdc"\n"axc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 进阶：
 * 
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢：
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * 两个字符串都只由小写字符组成。
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
    bool isSubsequence(string s, string t) {
        int n=s.length(),m=t.length(); //s的长度，t的长度
        int i=0,j=0; //i遍历s，j遍历t
        while (i<n&&j<m) //当s还没遍历完，t还没遍历完
        {
            if(s[i]==t[j]){ //如果相等，i往后移一位
                i++; 
            }
            j++;    //j每次都往后移一位
        }
        return i==n; //如果i遍历完了，说明s是t的子序列
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    cout << boolalpha;
    
    cout << "测试用例1: " << solution.isSubsequence("abc", "ahbgdc") << endl;
    cout << "测试用例2: " << solution.isSubsequence("axc", "ahbgdc") << endl;
    
    return 0;
}



/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */

