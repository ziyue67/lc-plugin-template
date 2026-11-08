/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30404
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (53.29%)
 * Likes:    1520
 * Dislikes: 0
 * Total Accepted:    357.5K
 * Total Submissions: 670.9K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3\n[5,3,6,2,4,null,7]\n0\n[]\n0'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 *
 * 一般来说，删除节点可分为两个步骤：
 *
 *
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 *
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 * 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 * 解释: 二叉树不包含值为 0 的节点
 *
 *
 * 示例 3:
 *
 * 输入: root = [], key = 0
 * 输出: []
 *
 *
 *
 * 提示:
 *
 *
 * 节点数的范围 [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 节点值唯一
 * root 是合法的二叉搜索树
 * -10^5 <= key <= 10^5
 *
 *
 *
 *
 * 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // 情况1没有 左节点
            if (!root->left)
                return root->right;
            // 情况2 没有右节点
            if (!root->right)
                return root->left;
            // 情况3 都有节点
            TreeNode *curr = root->right; // 定义节点 往右找
            while (curr->left)            // 往下找
            {
                curr = curr->left;
            }
            root->val = curr->val;                            // 改掉删除的值
            root->right = deleteNode(root->right, curr->val); // 挂载节点
        }
        return root;
    };
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
