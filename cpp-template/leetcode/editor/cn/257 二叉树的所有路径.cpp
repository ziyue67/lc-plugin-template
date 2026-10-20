/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30404
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (71.59%)
 * Likes:    1320
 * Dislikes: 0
 * Total Accepted:    537.8K
 * Total Submissions: 751.2K
 * Testcase Example:  '[1,2,3,null,5]\n[1]'
 *
 * 给你一个二叉树的根节点 root。
 *
 * 按 任意顺序 ，返回所有 从根节点到叶子节点 的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
    void dfs(TreeNode *root, vector<int> &path, vector<string> &res)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            string s;
            for (int i = 0; i < path.size(); ++i)
            {
                if (i > 0)
                    s += "->";
                s += to_string(path[i]);
            }
            res.push_back(s);
        }
        if (root->left)
            dfs(root->left, path, res);
        if (root->right)
            dfs(root->right, path, res);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        // 递归法
        // vector<string> result;
        // if (!root)
        //     return {};
        // if (!root->left && !root->right)
        // {
        //     result.push_back(to_string(root->val));
        // }
        // else
        // {
        //     vector<string> Leftpaths = binaryTreePaths(root->left);
        //     for (auto &path : Leftpaths)
        //     {
        //         result.push_back(to_string(root->val) + "->" + path);
        //     }
        //     vector<string> rightpaths = binaryTreePaths(root->right);
        //     for (auto &path : rightpaths)
        //     {
        //         result.push_back(to_string(root->val) + "->" + path);
        //     }
        // }
        // return result;

        vector<string> res;
        vector<int> path;
        if (root)
        {
            dfs(root, path, res);
        }
        return res;
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
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
