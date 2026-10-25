/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30404
 *
 * [226] 翻转二叉树
 *
 * https://leetcode.cn/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (82.54%)
 * Likes:    2127
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 1.9M
 * Testcase Example:  '[4,2,7,1,3,6,9]\n[2,1,3]\n[]'
 *
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [2,1,3]
 * 输出：[2,3,1]
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在 [0, 100] 内
 * -100 <= Node.val <= 100
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
    void Treee(TreeNode *node)
    {
        if (node == nullptr)
            return;
        TreeNode *child = node->left;
        node->left = node->right;
        node->right = child;
        Treee(node->left);  // 递归翻转左子树
        Treee(node->right); // 递归翻转右子树
    }

    TreeNode *invertTree(TreeNode *root)
    {

        // if (!root)
        //     return nullptr;
        // TreeNode *left = invertTree(root->left);
        // TreeNode *right = invertTree(root->right);
        // root->left = right;
        // root->right = left;
        // return root;
        if (!root)
            return nullptr;
        Treee(root);
        return root;
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
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
