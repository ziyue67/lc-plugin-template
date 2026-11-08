/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30404
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (76.21%)
 * Likes:    2063
 * Dislikes: 0
 * Total Accepted:    954.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,5,3,4,null,6]\n[]\n[0]'
 *
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 *
 *
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 *
 *
 * 示例 2：
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数在范围 [0, 2000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
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
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        if (root == nullptr)
            return;
        auto dfs = [&](auto &dfs_, TreeNode *node) -> void
        {
            if (node == nullptr)
                return;
            dfs_(dfs_, node->left);
            dfs_(dfs_, node->right);
        };
        if (curr->left != nullptr)
        {
            TreeNode *temp = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
            while (curr->right != nullptr)
            {
                curr = curr->right; // 移动到右子树的最右节点
            }
            curr->right = temp;
        };
        return flatten(root->right);
    }
}

;
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
