/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30404
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (73.51%)
 * Likes:    1419
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,null,2,3]\n[1,2,3,4,5,null,8,null,null,6,7,9]\n[]\n[1]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 *
 * 输出：[1,2,3]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * 输出：[1,2,4,5,6,7,3,8,9]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1]
 *
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <stack>
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
    // VLR   递归
    // void preorderHelper(TreeNode *node, vector<int> &result)
    // {
    //     if (node == nullptr)
    //         return;
    //     result.push_back(node->val);
    //     preorderHelper(node->left, result);
    //     preorderHelper(node->right, result);
    // }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // preorderHelper(root, res);
        // return res;

        // 方法2 栈
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right != nullptr)
            {
                stk.push(node->right);
            }
            if (node->left != nullptr)
            {
                stk.push(node->left);
            }
        }
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
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
