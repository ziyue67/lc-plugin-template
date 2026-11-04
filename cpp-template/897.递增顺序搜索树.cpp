/*
 * @lc app=leetcode.cn id=897 lang=cpp
 * @lcpr version=30404
 *
 * [897] 递增顺序搜索树
 *
 * https://leetcode.cn/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (73.80%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    92.9K
 * Total Submissions: 125.9K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]\n[5,1,7]'
 *
 * 给你一棵二叉搜索树的 root ，请你 按中序遍历
 * 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *
 *
 * 示例 2：
 *
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的取值范围是 [1, 100]
 * 0 <= Node.val <= 1000
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
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *prev = nullptr;
        TreeNode *newRoot = nullptr;
        auto dfs = [&](auto &self, TreeNode *node, TreeNode *prve) -> void
        {
            if (node == nullptr)
                return;
            self(self, node->left, prev);
            if (prev == nullptr)
            {
                newRoot = node;
            }
            else
            {
                prev->right = node;
            }
            prev = node;
            node->left = nullptr;
            self(self, node->right, prev);
        };
        dfs(dfs, root, root);
        return newRoot;
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
// [5,3,6,2,4,null,8,1,null,null,null,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,7]\n
// @lcpr case=end

 */
