/*
 * @lc app=leetcode.cn id=513 lang=cpp
 * @lcpr version=30404
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.92%)
 * Likes:    664
 * Dislikes: 0
 * Total Accepted:    358.9K
 * Total Submissions: 485.4K
 * Testcase Example:  '[2,1,3]\n[1,2,3,4,null,5,6,null,null,7]'
 *
 * 给定一个二叉树的 根节点 root。
 *
 * 请找出该二叉树的 最底层 最左边 节点的值。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：root = [2,1,3]
 * 输出：1
 * 解释：最后一行是 [1, 3]，因此最左边的值是 1。
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 * 输入：[1,2,3,4,null,5,6,null,null,7]
 * 输出：7
 * 解释：最后一层只有节点 7。
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1, 10^4]
 * -2^31 <= Node.val <= 2^31 - 1 
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <queue>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int res = root->val;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0)
                {
                    res = node->val;
                }
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
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
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

 */
