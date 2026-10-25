/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30404
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (49.52%)
 * Likes:    2381
 * Dislikes: 0
 * Total Accepted:    710.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n' +
  '8\n' +
  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n' +
  '22'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 *
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 *
 *
 * 示例 2：
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9 <= Node.val <= 10^9 
 * -1000 <= targetSum <= 1000 
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
    int PathSum(TreeNode *root, long long targetSum)
    {
        if (!root)
            return 0;
        int ans = 0;
        if (root->val == targetSum)
            ans++;
        ans += PathSum(root->left, targetSum - root->val);  // 递归左子树寻找路径和为 targetSum - root->val 的路径
        ans += PathSum(root->right, targetSum - root->val); // 递归右子树寻找路径和为 targetSum - root->val 的路径
        return ans;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return PathSum(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
        // unordered_map<long long, int> Count;
        // Count[0] = 1; // 初始化前缀和为 0 的路径数量为 1
        // int ans = 0;
        // auto dfs = [&](this auto &&self, TreeNode *node, long long sum_) -> void { // 使用 lambda 表达式定义递归函数
        //     if (!node)
        //     {
        //         return;
        //     }
        //     sum_ += node->val;              // 更新当前路径的前缀和
        //     ans += Count[sum_ - targetSum]; // 如果存在前缀和为 sum_ - targetSum 的路径，则说明当前路径的和为 targetSum
        //     Count[sum_]++;                  // 更新前缀和的路径数量
        //     self(node->left, sum_);
        //     self(node->right, sum_);
        //     Count[sum_]--; // 回溯，移除当前节点的前缀和
        // };
        // dfs(root, 0);
        // return ans;
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
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
