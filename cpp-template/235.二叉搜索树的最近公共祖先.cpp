/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30404
 *
 * [235] 二叉搜索树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (72.80%)
 * Likes:    1377
 * Dislikes: 0
 * Total Accepted:    558.1K
 * Total Submissions: 766.6K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n' +
  '2\n' +
  '8\n' +
  '[6,2,8,0,4,7,9,null,null,3,5]\n' +
  '2\n' +
  '4\n' +
  '[2,1]\n' +
  '2\n' +
  '1'
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 *
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 *
 *
 * 示例 2:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 *
 *
 *
 * 说明:
 *
 *
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 1) root 为空：说明这条路径到底了，返回 nullptr
        // 2) root == p：当前节点就是 p，直接返回 p（p 自己也算 p 的祖先）
        // 3) root == q：当前节点就是 q，直接返回 q
        if (!root || root == p || root == q)
            return root;
        // left  ：在左子树中搜索 p 和 q 的结果
        // right ：在右子树中搜索 p 和 q 的结果
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // left 和 right 都非空，说明 p、q 分别位于左右两侧子树
        // 那么当前 root 就是它们"分岔"的节点，即最近公共祖先
        if (left && right)
            return root;
        // - left 非空、right 为空：p 和 q 都在左子树（或只找到其中之一），向上返回 left
        // - right 非空、left 为空：p 和 q 都在右子树（或只找到其中之一），向上返回 right
        return left ? left : right;
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
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n1\n
// @lcpr case=end

 */
