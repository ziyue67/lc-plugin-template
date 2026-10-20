/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30404
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (60.27%)
 * Likes:    1732
 * Dislikes: 0
 * Total Accepted:    817.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]\n[1,2,2,3,3,null,null,4,4]\n[]'
 *
 * 给定一个二叉树，判断它是否是 平衡二叉树  
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 <= Node.val <= 10^4
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
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return 1 + max(leftHeight, rightHeight); // 返回当前节点的高度
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1) // 如果左右子树高度差大于1，则不是平衡二叉树
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right); // 递归判断左右子树是否平衡
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
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
