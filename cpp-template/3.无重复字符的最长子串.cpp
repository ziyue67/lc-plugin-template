/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30307
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),ans=0,left=0;//滑动窗口 左边界 右边界 最大长度 初始化 为0 0 0
        unordered_map<char,int>cnt;//记录字符出现的次数
        for (int right = 0; right < n; right++) //右边界从0开始遍历到n-1
        {
            char c=s[right]; //记录当前字符
            cnt[c]++; //当前字符出现次数+1
            while (cnt[c]>1) //如果当前字符出现次数大于1
            {
                cnt[s[left]]--; //左边界字符出现次数-1
                left++; //左边界右移
            }
            ans=max(ans,right-left+1); //更新最大长度
            

        }
        return ans; //返回最大长度
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

