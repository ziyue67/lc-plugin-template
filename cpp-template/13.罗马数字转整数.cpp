/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=30400
 *
 * [13] 罗马数字转整数
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 单个罗马数字到整数的映射
unordered_map<char, int> ROMAN = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution
{
public:
  int romanToInt(string s)
  {
    int ans = 0;
    for (int i = 0; i + 1 < s.size(); i++)
    { // 遍历 s
      int x = ROMAN[s[i]], y = ROMAN[s[i + 1]];
      ans += x < y ? -x : x; // 累加 x 或者 -x，这里 y 只是用来辅助判断 x 的正负
    }
    return ans + ROMAN[s.back()]; // 加上最后一个罗马数字
  }
};

// @lc code=end

/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */
