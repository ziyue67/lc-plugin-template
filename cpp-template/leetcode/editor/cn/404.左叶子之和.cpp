/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30404
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (64.15%)
 * Likes:    817
 * Dislikes: 0
 * Total Accepted:    421.8K
 * Total Submissions: 657.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]\n[1]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 *
 *
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
    // int LeftLeaves(TreeNode *root, vector<int> &res)
    // {
    //     if (!root)
    //         return 0;
    //     if (root->left && !root->left->left && !root->left->right)
    //     {
    //         res.push_back(root->left->val);
    //     }
    //     LeftLeaves(root->left, res);
    //     LeftLeaves(root->right, res);
    //     return 0;
    // }
    int sumOfLeftLeaves(TreeNode *root)
    {
        // if (!root)
        //     return 0;
        // vector<int> res;
        // LeftLeaves(root, res);
        // int sum = 0;
        // for (auto v : res)
        // {
        //     sum += v;
        // }
        // return sum;
        if (!root)
            return 0;
        int sum = 0;
        vector<int> res;                                           // 用于存储节点的值
        if (root->left && !root->left->left && !root->left->right) // 判断左子节点是否为叶子节点
        {
            sum += root->left->val;
            res.push_back(root->left->val);
        }
        sum += sumOfLeftLeaves(root->left);  // 递归遍历左子树
        sum += sumOfLeftLeaves(root->right); // 递归遍历右子树
        return sum;
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
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
