/*
 * @lc app=leetcode.cn id=559 lang=cpp
 * @lcpr version=30404
 *
 * [559] N 叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (75.62%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    201K
 * Total Submissions: 265.8K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\n' +
  '[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 *
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 *
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树的深度不会超过 1000 。
 * 树的节点数目位于 [0, 10^4] 之间。
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    // void maxDepthHelper(Node *root, int &depth)
    // {
    //     if (!root)
    //         return;
    //     depth++;
    //     for (auto child : root->children)
    //         maxDepthHelper(child, depth);
    //     depth--;
    // }
    int maxDepth(Node *root)
    {
        // if (!root)
        //     return 0;
        // int best = 0;
        // for (Node *child : root->children)
        //     best = max(best, maxDepth(child));
        // return 1 + best;
        if (!root)
            return 0;
        int depth = 0;
        for (Node *child : root->children)
        {
            int childDepth = maxDepth(child);
            depth = max(depth, childDepth);
        }
        return 1 + depth;
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
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */
