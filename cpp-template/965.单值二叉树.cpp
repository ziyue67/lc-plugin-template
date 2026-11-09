/*
 * @lc app=leetcode.cn id=965 lang=cpp
 * @lcpr version=30404
 *
 * [965] 单值二叉树
 *
 * https://leetcode.cn/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (70.54%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    113.4K
 * Total Submissions: 160.8K
 * Testcase Example:  '[1,1,1,1,1,null,1]\n[2,2,2,5,2]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 *
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[2,2,2,5,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
    bool isUnivalTree(TreeNode *root)
    {
// 写法1  单递归 孩子与父亲比较
#if 0
        if (!root)
            return true;
        if (root->left && root->left->val != root->val)
            return false;
        if (root->right && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
#endif
        if (!root)
            return true;
        auto check = [&](auto &check, TreeNode *node, int val) -> bool
        {
            if (!node)
                return true;
            if (node->left && node->left->val != node->val)
                return false;
            if (node->right && node->right->val != node->val)
                return false;
            return check(check, node->left, val) && check(check, node->right, val);
        };
        return check(check, root, root->val);
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
// [1,1,1,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,5,2]\n
// @lcpr case=end

 */
