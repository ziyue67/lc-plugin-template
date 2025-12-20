/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30304
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle) {
        int h=haystack.size(), n=needle.size();
        for (int i = 0; i <= h-n; i++)
        {
            int j=i;
            int k=0;
            for(k = 0; k < n && haystack[j] == needle[k];){
                j++;
                k++;
            }
            if(k==n){
                return i;
            }
        }
        return -1;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

