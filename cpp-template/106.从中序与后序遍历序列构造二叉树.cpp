/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30404
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (73.07%)
 * Likes:    1424
 * Dislikes: 0
 * Total Accepted:    553.1K
 * Total Submissions: 756.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]\n[-1]\n[-1]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        auto dfs = [&](this auto &&dfs, int in_l, int post_l, int post_r) -> TreeNode *
        {
            if (post_l == post_r)
                return nullptr;
            int left_size = index[postorder[post_r - 1]] - in_l;
            TreeNode *left = dfs(in_l, post_l, post_l + left_size);
            TreeNode *right = dfs(in_l + left_size + 1, post_l + left_size, post_r - 1);
            return new TreeNode(postorder[post_r - 1], left, right);
        };
        return dfs(0, 0, n);
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
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
