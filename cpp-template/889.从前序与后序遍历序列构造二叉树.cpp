/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30404
 *
 * [889] 从前序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (70.74%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    80.1K
 * Total Submissions: 113.2K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n[1]\n[1]'
 *
 * 给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder
 * 是同一棵树的后序遍历，重构并返回二叉树。
 *
 * 如果存在多个答案，您可以返回其中 任何 一个。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 *
 *
 * 示例 2:
 *
 * 输入: preorder = [1], postorder = [1]
 * 输出: [1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= preorder.length <= 30
 * 1 <= preorder[i] <= preorder.length
 * preorder 中所有值都 不同
 * postorder.length == preorder.length
 * 1 <= postorder[i] <= postorder.length
 * postorder 中所有值都 不同
 * 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            index[postorder[i]] = i;
        }
        auto dfs = [&](this auto &&dfs, int pre_l, int pre_r, int pos_l, int pos_r) -> TreeNode *
        {
            if (pre_l == pre_r)
                return nullptr;
            if (pre_l + 1 == pre_r)
                return new TreeNode(preorder[pre_l]);

            int left_size = index[preorder[pre_l + 1]] - pos_l + 1;
            TreeNode *left = dfs(pre_l + 1, pre_l + 1 + left_size, pos_l, pos_l + left_size);
            TreeNode *right = dfs(pre_l + 1 + left_size, pre_r, pos_l + left_size, pos_r - 1);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n);
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
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */
