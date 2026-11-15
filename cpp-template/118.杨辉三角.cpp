/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30404
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (77.83%)
 * Likes:    1401
 * Dislikes: 0
 * Total Accepted:    941.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '5\n1'
 *
 * 给定一个非负整数 numRows。
 *
 * 返回「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int> row;
        for (int i = 0; i < numRows; i++)
        {
            row.resize(i + 1, 1);
            // for (int j = i - 1; j >= 1; j--)
            // {
            //     row[j] = row[j] + row[j - 1];
            // }
            for (int j = 1; j < i; j++)
            {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        };
        return res;
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
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
