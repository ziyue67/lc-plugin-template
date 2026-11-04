/*
 * @lc app=leetcode.cn id=671 lang=cpp
 * @lcpr version=30404
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (48.54%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    89.3K
 * Total Submissions: 184K
 * Testcase Example:  '[2,2,5,null,null,5,7]\n[2,2,2]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
 *
 * 更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。
 *
 * 给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。
 *
 * 如果第二小的值不存在的话，输出 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [2,2,5,null,null,5,7]
 * 输出：5
 * 解释：最小的值是 2 ，第二小的值是 5 。
 *
 *
 * 示例 2：
 *
 * 输入：root = [2,2,2]
 * 输出：-1
 * 解释：最小的值是 2, 但是不存在第二小的值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 25] 内
 * 1 <= Node.val <= 2^31 - 1
 * 对于树中每个节点 root.val == min(root.left.val, root.right.val)
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
    int findSecondMinimumValue(TreeNode *root)
    {
        int first = root->val;  // 根节点的值就是最小值
        long second = LONG_MAX; // 使用 long 类型来避免溢出
        auto dfs = [&](TreeNode *node, auto &dfs) -> void
        {
            if (!root)
                return;
            if (root->val > first && root->val < second) // 找到比 first 大且比 second 小的值
            {
                second = root->val; // 更新 second
            }
            dfs(root->left, dfs);
            dfs(root->right, dfs);
        };
        dfs(root, dfs);
        return second == LONG_MAX ? -1 : second; // 如果 second 仍然是 LONG_MAX，说明没有找到第二小的值
    };
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
// [2,2,5,null,null,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

 */
