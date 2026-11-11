/*
 * @lc app=leetcode.cn id=508 lang=cpp
 * @lcpr version=30404
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode.cn/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (76.58%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    60.8K
 * Total Submissions: 79.4K
 * Testcase Example:  '[5,2,-3]\n[5,2,-5]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 *
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入: root = [5,2,-5]
 * 输出: [2]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
    unordered_map<int, int> countMap;
    int maxCount = 0;
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        // if (!root)
        //     return {};
        // unordered_map<int, int> Summap;
        // int maxindex = 0;
        // auto dfs = [&](auto &dfs, TreeNode *node) -> int
        // {
        //     if (!node)
        //         return 0;
        //     int leftsum = dfs(dfs, node->left);
        //     int rightsum = dfs(dfs, node->right);

        //     int Sum = leftsum + rightsum + node->val;
        //     Summap[Sum]++;
        //     maxindex = max(maxindex, Summap[Sum]);

        //     return Sum;
        // };
        // dfs(dfs, root);
        // vector<int> res;
        // for (auto pair : Summap)
        // {
        //     if (pair.second == maxindex)
        //     {
        //         res.push_back(pair.first);
        //     }
        // };
        // return res;
        dfs(root);
        vector<int> res;
        for (auto &[sum, cnt] : countMap)
        {
            if (cnt == maxCount)
                res.push_back(sum);
        }
        return res;
    }
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxCount = max(maxCount, ++countMap[sum]);
        return sum;
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
// [5,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,-5]\n
// @lcpr case=end

 */
