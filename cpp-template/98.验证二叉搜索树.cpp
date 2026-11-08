/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30404
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (41.62%)
 * Likes:    2833
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,1,3]\n[5,1,4,null,null,3,6]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 严格小于 当前节点的数。
 * 节点的右子树只包含 严格大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
    bool isValidBST(TreeNode *root)
    {
        long min = LONG_MIN; // 设置左子树低的值
        long max = LONG_MAX; // 设置右子树的高的值
        if (!root)           // 空子树
            return true;
        auto dfs = [&](auto &dfs_, TreeNode *node, long min, long max) -> bool
        {
            if (!node)
                return true;
            if (node->val <= min || node->val >= max)
            {
                return false;
            }
            bool left = dfs_(dfs_, node->left, min, node->val);
            bool right = dfs_(dfs_, node->right, node->val, max);
            return left && right;
        };
        return dfs(dfs, root, min, max);
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
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
