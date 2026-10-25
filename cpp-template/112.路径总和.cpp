/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=30404
 *
 * [112] 路径总和
 *
 * https://leetcode.cn/problems/path-sum/description/
 *
 * algorithms
 * Easy (56.12%)
 * Likes:    1557
 * Dislikes: 0
 * Total Accepted:    931.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n[1,2,3]\n5\n[]\n0'
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点
 * 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 * 解释：等于目标和的根节点到叶节点路径如上图所示。
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 * 解释：树中存在两条根节点到叶子节点的路径：
 * (1 --> 2): 和为 3
 * (1 --> 3): 和为 4
 * 不存在 sum = 5 的根节点到叶子节点的路径。
 *
 * 示例 3：
 *
 * 输入：root = [], targetSum = 0
 * 输出：false
 * 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 5000] 内
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <vector>
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
    bool dsh(TreeNode *root, vector<int> &path, int targetSum)
    {
        if (!root)
            return false;
        path.push_back(root->val);                           // 将当前节点加入路径
        if (root->left == nullptr && root->right == nullptr) // 如果是叶子节点
        {

            int sum = 0;
            for (auto &v : path) // 遍历路径中的节点值，计算路径和值
            {
                sum += v;
            }
            if (sum == targetSum) // 如果路径和等于目标和，返回true
            {
                return true;
            }
        }
        if (dsh(root->left, path, targetSum))
            return true; // 如果左子树找到路径，直接返回true
        if (dsh(root->right, path, targetSum))
            return true; // 如果右子树找到路径，直接返回true
        path.pop_back(); // 移除当前节点
        return false;    // 如果没有找到路径，返回false
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        vector<int> path;
        return dsh(root, path, targetSum);
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
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
