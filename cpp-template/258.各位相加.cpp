/*
 * @lc app=leetcode.cn id=258 lang=cpp
 * @lcpr version=30400
 *
 * [258] 各位相加
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
  int addDigits(int num)
  {
    // 当数字大于等于10时，持续计算各位数字之和，直到结果小于10
    // while (num >= 10)
    // {
    //   int sum = 0;
    //   // 遍历当前数字的每一位
    //   while (num > 0)
    //   {
    //     sum += num % 10; // 取出最后一位并累加到总和
    //     num /= 10;       // 去掉最后一位
    //   }
    //   // 将计算出的各位和作为新的num，进入下一轮循环
    //   num = sum;
    // }
    // // 返回最终小于10的结果
    // return num;
    if (num == 0)  
      return 0; // 特殊情况处理
    return 1 + (num - 1) % 9; // 使用数学公式计算
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
// 38\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
