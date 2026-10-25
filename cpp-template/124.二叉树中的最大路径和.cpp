/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30404
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (48.55%)
 * Likes:    2638
 * Dislikes: 0
 * Total Accepted:    803.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3]\n[-10,9,20,null,null,15,7]'
 *
 * 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个
 * 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000 <= Node.val <= 1000
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
    // int maxSum = INT_MIN;
    // int dfs(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;

    //     // 返回：以 root 为端点、向下延伸的最大路径和（可为负，但对外只取 max(0,·)）
    //     int left = max(0, dfs(root->left));
    //     int right = max(0, dfs(root->right));
    //     maxSum = max(maxSum, root->val + left + right);
    //     return root->val + max(left, right);
    // }
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        // dfs(root);
        // return maxSum;
        auto dfs = [&](this auto &&dfs, TreeNode *root) -> int
        {
            if (!root)
                return 0;

            // 返回：以 root 为端点、向下延伸的最大路径和（可为负，但对外只取 max(0,·)）
            int left = max(0, dfs(root->left));
            int right = max(0, dfs(root->right));
            maxSum = max(maxSum, root->val + left + right);
            return max(left, right) + root->val;
        };
        dfs(root);
        return maxSum;
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
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
