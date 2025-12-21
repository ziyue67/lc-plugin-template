/*
 * @lc app=leetcode.cn id=LCR 136 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 136] 删除链表的节点
 *
 * https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (59.01%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    416.6K
 * Total Submissions: 706.1K
 * Testcase Example:  '[4,5,1,9]\n5\n[4,5,1,9]\n1'
 *
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 *
 * 返回删除后的链表的头节点。
 *
 * 示例 1：
 *
 * 输入：head = [4,5,1,9], val = 5
 * 输出：[4,1,9]
 * 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 *
 *
 * 示例 2：
 *
 * 输入：head = [4,5,1,9], val = 1
 * 输出：[4,5,9]
 * 解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 *
 *
 *
 *
 * 说明：
 *
 *
 * 题目保证链表中节点的值互不相同
 * 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
 *
 *
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
    ListNode *deleteNode(ListNode *head, int val)
    {
        // 存放删除 val 的链表
        ListNode *dummy = new ListNode(-1);
        // q 指针负责生成结果链表
        ListNode *q = dummy;
        // p 负责遍历原链表
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val != val)
            {
                // 把值不为 val 的节点接到结果链表上
                q->next = p;
                q = q->next;
            }
            // 断开原链表中的每个节点的 next 指针
            ListNode *temp = p->next;  // 保存下一个节点
            p->next = nullptr;// 断开 next 指针
            p = temp; // 指针后移
        }
        // Make sure to connect the last node of the new list to nullptr
        q->next = nullptr;

        return dummy->next;
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
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */
