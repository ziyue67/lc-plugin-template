/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30304
 *
 * [202] 快乐数
 *
 * https://leetcode.cn/problems/happy-number/description/
 *
 * algorithms
 * Easy (66.01%)
 * Likes:    1764
 * Dislikes: 0
 * Total Accepted:    702.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '19\n2'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 *
 *
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * 示例 2：
 *
 * 输入：n = 2
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
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
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow); // 慢指针走1步
            fast = bitSquareSum(fast); // 快指针先算1次
            fast = bitSquareSum(fast); // 快指针再算1次（共走2步）
        } while (slow != fast); // 循环直到快慢指针相遇

        return slow == 1; // 相遇值为1则是快乐数
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
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
