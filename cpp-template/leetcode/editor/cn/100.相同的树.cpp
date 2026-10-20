/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30404
 *
 * [100] 相同的树
 *
 * https://leetcode.cn/problems/same-tree/description/
 *
 * algorithms
 * Easy (64.21%)
 * Likes:    1319
 * Dislikes: 0
 * Total Accepted:    786.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]\n[1,2,3]\n[1,2]\n[1,null,2]\n[1,2,1]\n[1,1,2]'
 *
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 *
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：p = [1,2,3], q = [1,2,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：p = [1,2], q = [1,null,2]
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：p = [1,2,1], q = [1,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两棵树上的节点数目都在范围 [0, 100] 内
 * -10^4 <= Node.val <= 10^4
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
    // void inorder(TreeNode *root, vector<string> &res)
    // {
    //     if (!root)
    //     {
    //         res.push_back("#");
    //         return;
    //     }
    //     res.push_back(to_string(root->val)); // VLR
    //     inorder(root->left, res);
    //     inorder(root->right, res);
    // }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // vector<string> res1, res2;
        // inorder(p, res1);
        // inorder(q, res2);
        // return res1 == res2;
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */
