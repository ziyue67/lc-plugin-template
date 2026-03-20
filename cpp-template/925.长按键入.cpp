/*
 * @lc app=leetcode.cn id=925 lang=cpp
 * @lcpr version=30400
 *
 * [925] 长按键入
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
  bool isLongPressedName(string name, string typed)
  {
    int i = 0, j = 0; // 双指针
    while (i < name.size() && j < typed.size()) // 遍历两个字符串
    {
      if (name[i] == typed[j]) // 当前字符相等 则两个指针都后移
      {
        i++;
        j++;
      }
      else if (j > 0 && typed[j] == typed[j - 1]) // 当前字符不相等 但 typed[j] 与 typed[j-1] 相等，说明 typed[j] 是重复的字符，则 j 后移
      {
        j++;
      }
      else
      {
        return false; // 当前字符不相等 且 typed[j] 与 typed[j-1] 不相等，说明 typed[j] 不是重复的字符，则返回 false
      }
    }
    // 检查 typed 剩余的字符必须全是最后一个字符的重复
    while (j < typed.size()) // 如果 typed 剩余的字符不是最后一个字符的重复，则返回 false
    {
      if (typed[j] == typed[j - 1]) // 如果 typed 剩余的字符是最后一个字符的重复，则 j 后移
      {
        j++;
      }
      else
      {
        return false;
      } 
    }
    return i == name.size(); // 如果 name 剩余的字符不是最后一个字符的重复，则返回 false
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
// "alex"\n"aaleex"\n
// @lcpr case=end

// @lcpr case=start
// "saeed"\n"ssaaedd"\n
// @lcpr case=end

 */
