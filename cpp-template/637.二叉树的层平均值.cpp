/*
 * @lc app=leetcode.cn id=637 lang=cpp
 * @lcpr version=30404
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (72.14%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    308.5K
 * Total Submissions: 427.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]\n[3,9,20,15,7]'
 *
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 *
 *
 * 示例 2:
 *
 *
 *
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <queue>
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;  // 每层平均值的结果数组
        queue<TreeNode *> q; // 队列存放待处理的节点
        q.push(root);        // 根节点先入队
        while (!q.empty())
        {
            int level_size = q.size(); // 当前层的节点个数（队列长度即本层节点数）
            double sum = 0;            // 本层节点值之和
            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = q.front(); // 取出队头节点
                q.pop();                    // 出队
                sum += node->val;           // 累加本节点值
                if (node->left)             // 左孩子非空
                    q.push(node->left);     // 入队，等下一层处理
                if (node->right)            // 右孩子非空
                    q.push(node->right);    // 入队，等下一层处理
            }
            res.push_back(sum / level_size); // 本层平均值加入结果
        }
        return res; // 返回所有层的平均值
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
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,9,20,15,7]\n
// @lcpr case=end

 */
