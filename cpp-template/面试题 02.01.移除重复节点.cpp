/*
 * @lc app=leetcode.cn id=面试题 02.01 lang=cpp
 * @lcpr version=30305
 *
 * [面试题 02.01] 移除重复节点
 *
 * https://leetcode.cn/problems/remove-duplicate-node-lcci/description/
 *
 * LCCI
 * Easy (66.43%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    112.1K
 * Total Submissions: 168.7K
 * Testcase Example:  '[1, 2, 3, 3, 2, 1]\n[1, 1, 1, 1, 2]'
 *
 * 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
 *
 * 示例1：
 *
 * ⁠输入：[1, 2, 3, 3, 2, 1]
 * ⁠输出：[1, 2, 3]
 *
 *
 * 示例2：
 *
 * ⁠输入：[1, 1, 1, 1, 2]
 * ⁠输出：[1, 2]
 *
 *
 * 提示：
 *
 *
 * 链表长度在[0, 20000]范围内。
 * 链表元素在[0, 20000]范围内。
 *
 *
 * 进阶：
 *
 * 如果不得使用临时缓冲区，该怎么解决？
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        
        ListNode *per = nullptr, *cur = head;//per指向当前节点的前一个节点，cur指向当前节点
        unordered_set<int> visited;//记录已经访问过的节点值
        while (cur != nullptr) //遍历链表
        {
            if (visited.find(cur->val) != visited.end()) //如果当前节点值已经访问过，则删除当前节点
            {
                per->next = cur->next;//per指向当前节点的下一个节点
            }else
            {
               visited.emplace(cur->val);//记录当前节点值
               per = cur;//per指向当前节点
            }
            cur=cur->next; //cur指向当前节点的下一个节点
        }
        return head;
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
// [1, 2, 3, 3, 2, 1]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1, 1, 2]\n
// @lcpr case=end

 */
