/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30404
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (80.59%)
 * Likes:    1847
 * Dislikes: 0
 * Total Accepted:    956K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-10,-3,0,5,9]\n[1,3]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 *
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // auto Tree = [&](auto &&Tree_, int left, int right) -> TreeNode *
        // {
        //     if (left > right)
        //         return nullptr;
        //     int mid = left + (right - left) / 2;        // 找到mid 中点
        //     TreeNode *root = new TreeNode(nums[mid]);   // 创建一个跟节点
        //     root->left = Tree_(Tree_, left, mid - 1);   // 递归左子树开
        //     root->right = Tree_(Tree_, mid + 1, right); // 递归右子树
        //     return root;
        // };
        // return Tree(Tree, 0, nums.size() - 1);
        auto Tree = [&](auto &&Tree_, int left, int right) -> TreeNode *
        {
            if (left > right)
            {
                return nullptr;
            }
            int mid = left + (right - left) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = Tree_(Tree_, left, mid - 1);
            root->right = Tree_(Tree_, mid + 1, right);
            return root;
        };
        return Tree(Tree, 0, nums.size() - 1);
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
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */
