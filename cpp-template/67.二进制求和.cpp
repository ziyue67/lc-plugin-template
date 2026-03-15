/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30400
 *
 * [67] 二进制求和
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
    string addBinary(string a, string b) {
      // 先把输入的这两个二进制串反转，低位放在前面，方便处理进位
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());

      // 存储结果
      string result;

      int m = a.size(), n = b.size();
      // carry 记录进位
      int carry = 0;
      int i = 0;

      // 开始类似 [2. 两数相加](#2) 的加法模拟逻辑
      // 只是这里运算的是二进制字符串
      while (i < max(m, n) || carry > 0)
      {
        int val = carry;
        val += i < m ? (a[i] - '0') : 0;
        val += i < n ? (b[i] - '0') : 0;
        result += (val % 2) + '0';
        carry = val / 2;
        i++;
      }

      // 反转结果字符串
      reverse(result.begin(), result.end());
      return result;
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */

