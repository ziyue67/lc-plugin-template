/*
 * @lc app=leetcode.cn id=165 lang=cpp
 * @lcpr version=30403
 *
 * [165] 比较版本号
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <sstream>
using namespace std;

// @lc code=start
class Solution
{
public:
  int compareVersion(string version1, string version2)
  {
    int i = 0, j = 0, n = version1.size(), m = version2.size(); // i,j分别指向两个字符串的起始位置
    while (i < n || j < m)
    {
      long long num1 = 0, num2 = 0; // num1,num2分别表示两个字符串的当前版本号
      while (i < n && version1[i] != '.') // 从左到右遍历version1，直到遇到'.'或者到达末尾
        num1 = num1 * 10 + (version1[i++] - '0'); // 将当前字符转换为数字并累加到num1中
      while (j < m && version2[j] != '.') // 从左到右遍历version2，直到遇到'.'或者到达末尾
        num2 = num2 * 10 + (version2[j++] - '0'); // 将当前字符转换为数字并累加到num2中
      if (num1 != num2) // 如果两个版本号不相等，则返回比较结果
        return num1 > num2 ? 1 : -1; // 如果num1大于num2，则返回1，否则返回-1
      i++;
      j++;
    }
    return 0;
  }
};
// @lc code=end

int main()
{
  Solution solution;
  cout << solution.compareVersion("1.2", "1.10") << endl;  // -1
  cout << solution.compareVersion("1.01", "1.001") << endl; // 0
  cout << solution.compareVersion("1.0", "1.0.0.0") << endl; // 0
}
