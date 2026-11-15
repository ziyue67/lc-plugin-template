/*
 * @lc app=leetcode.cn id=119 lang=cpp
 * @lcpr version=30404
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (69.63%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    376.1K
 * Total Submissions: 540.1K
 * Testcase Example:  '3\n0\n1'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
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
    vector<int> getRow(int rowIndex)
    {
        // vector<vector<int>> ans(2, vector<int>(rowIndex + 1, 1));
        // for (int i = 0; i <= rowIndex; i++)
        // {
        //     ans[i % 2][0] = 1; // 左边界
        //     ans[i % 2][i] = 1; // 右边界
        //     for (int j = 1; j < i; j++)
        //     {
        //         ans[i % 2][j] = ans[(i - 1) % 2][j - 1] + ans[(i - 1) % 2][j];
        //     }
        // }
        // return ans[rowIndex % 2];
        vector<int> row(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
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
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
