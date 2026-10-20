/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30404
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (64.00%)
 * Likes:    3197
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,2,2,3,4,4,3]\n[1,2,2,null,3,null,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isSymmetricHelper(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) // 判断两个节点是否都为空
        {
            return true;
        }
        if (!left || !right) // 判断两个节点是否有一个为空
        {
            return false;
        }
        if (left->val != right->val)
        { // 判断两个节点的值是否相等
            return false;
        }
        if (!isSymmetricHelper(left->left, right->right))
        { // 判断左子树的左节点和右子树的右节点是否对称
            return false;
        }
        if (!isSymmetricHelper(left->right, right->left))
        { // 判断左子树的右节点和右子树的左节点是否对称
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        TreeNode *left = root->left;   // 获取左子树的根节点
        TreeNode *right = root->right; // 获取右子树的根节点
        return isSymmetricHelper(left, right);
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
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
