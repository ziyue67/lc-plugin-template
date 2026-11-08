/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30404
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (73.34%)
 * Likes:    2823
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]\n[-1]\n[-1]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_map>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        auto dfs = [&](this auto &&dfs, int per_l, int per_r, int in_l) -> TreeNode *
        {
            if (per_l == per_r)
            {
                return nullptr;
            }
            int left_size = index[preorder[per_l]] - in_l;
            TreeNode *left = dfs(per_l + 1, per_l + 1 + left_size, in_l);
            TreeNode *right = dfs(per_l + 1 + left_size, per_r, in_l + 1 + left_size);
            return new TreeNode(preorder[per_l], left, right);
        };
        return dfs(0, n, 0);
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
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
