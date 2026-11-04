/*
 * @lc app=leetcode.cn id=783 lang=cpp
 * @lcpr version=30404
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode.cn/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (60.96%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    101.7K
 * Total Submissions: 166.9K
 * Testcase Example:  '[4,2,6,1,3]\n[1,0,48,null,null,12,49]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [2, 100]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 530：https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
 * 相同
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
    void dfs(TreeNode *root, vector<int> &tree)
    {
        if (root == nullptr)
            return;
        dfs(root->left, tree);
        tree.push_back(root->val);
        dfs(root->right, tree);
    }
    int minDiffInBST(TreeNode *root)
    {
        int first = root->val;
        long second = LONG_MAX;
        vector<int> tree;
        dfs(root, tree);
        if (root->val > first && root->val < second)
        {
            second = root->val;
        }
        for (int i = 1; i < tree.size(); i++) // 遍历数组，寻找最小差值
        {
            if (tree[i] - tree[i - 1] < second)
            {
                second = tree[i] - tree[i - 1];
            }
        }
        return second;
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
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */
