/*
 * @lc app=leetcode.cn id=2235 lang=cpp
 * @lcpr version=30305
 *
 * [2235] 两整数相加
 *
 * https://leetcode.cn/problems/add-two-integers/description/
 *
 * algorithms
 * Easy (74.23%)
 * Likes:    397
 * Dislikes: 0
 * Total Accepted:    205.5K
 * Total Submissions: 276.8K
 * Testcase Example:  '12\n5\n-10\n4'
 *
 * 给你两个整数 num1 和 num2，返回这两个整数的和。
 * 
 * 
 * 示例 1：
 * 
 * 输入：num1 = 12, num2 = 5
 * 输出：17
 * 解释：num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num1 = -10, num2 = 4
 * 输出：-6
 * 解释：num1 + num2 = -6 ，因此返回 -6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100 <= num1, num2 <= 100
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
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 12\n5\n
// @lcpr case=end

// @lcpr case=start
// -10\n4\n
// @lcpr case=end

 */

