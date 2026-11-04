/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30404
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode.cn/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (45.51%)
 * Likes:    637
 * Dislikes: 0
 * Total Accepted:    349.4K
 * Total Submissions: 767.9K
 * Testcase Example:  '16\n14'
 *
 * 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 *
 * 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
 *
 * 不能使用任何内置的库函数，如  sqrt 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：num = 16
 * 输出：true
 * 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
 *
 *
 * 示例 2：
 *
 * 输入：num = 14
 * 输出：false
 * 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num <= 2^31 - 1
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
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // if (num == 1)
        //     return true;
        // for (long long i = 1; i * i <= num; i++)
        // {
        //     if (i * i == num)
        //     {
        //         return true;
        //     }
        // }
        // return false;
        int left = 1, right = num;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == num)
            {
                return true;
            }
            else if (square < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
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
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
