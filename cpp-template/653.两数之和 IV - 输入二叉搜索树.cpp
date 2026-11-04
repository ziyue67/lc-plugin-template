/*
 * @lc app=leetcode.cn id=653 lang=cpp
 * @lcpr version=30404
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 *
 * https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (63.86%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    135K
 * Total Submissions: 211.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9\n[5,3,6,2,4,null,7]\n28'
 *
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 *
 *
 *
 * 示例 1：
 *
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 *
 *
 * 示例 2：
 *
 * 输入: root = [5,3,6,2,4,null,7], k = 28
 * 输出: false
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * 题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
 * -10^5 <= k <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_set>
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
    // void dfs(TreeNode *root, vector<int> &sum)
    // {
    //     if (root == nullptr)
    //         return;
    //     dfs(root->left, sum); // 递归遍历左子树
    //     sum.push_back(root->val);
    //     dfs(root->right, sum); // 递归遍历右子树
    // }
    bool dfs(TreeNode *root, int k, unordered_set<int> &seen)
    {
        if (root == nullptr)
            return false;
        if (seen.count(k - root->val)) // 如果在已访问的节点中找到了与当前节点值的差值，则返回 true
            return true;
        seen.insert(root->val);                                       // 将当前节点值加入已访问的节点集合
        return dfs(root->left, k, seen) || dfs(root->right, k, seen); // 递归遍历左子树和右子树
    }
    bool findTarget(TreeNode *root, int k)
    {
        // if (root == nullptr)
        //     return false;
        // vector<int> sum;
        // dfs(root, sum);
        // sort(sum.begin(), sum.end());
        // int left = 0;
        // int right = sum.size() - 1;
        // while (left < right)
        // {
        //     int currSum = sum[left] + sum[right];
        //     if (currSum == k)
        //     {
        //         return true;
        //     }
        //     else if (currSum < k)
        //     {
        //         left++;
        //     }
        //     else
        //     {
        //         right--;
        //     }
        // }
        // return false;
        unordered_set<int> seen; // 用于存储已经访问过的节点值
        return dfs(root, k, seen);
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
// [5,3,6,2,4,null,7]\n9\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n28\n
// @lcpr case=end

 */
