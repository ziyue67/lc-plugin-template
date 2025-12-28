/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30305
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (67.77%)
 * Likes:    1646
 * Dislikes: 0
 * Total Accepted:    410.4K
 * Total Submissions: 605.5K
 * Testcase Example:  '[1,2,3,4]\n[1,2,3,4,5]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * 请将其重新排列后变为：
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
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
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;//快慢指针找到中点
        while (fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev=nullptr,*cur=slow,*next=nullptr; //反转后半部分链表
        while (cur)
        {
            next=cur->next; //保存下一个节点
            cur->next=prev; //反转指针
            prev=cur; //前驱节点后移
            cur=next; //当前节点后移
        }
        ListNode *first=head,*second=prev; //合并两个链表
        while (second->next) //当后半部分链表不为空时
        {
            ListNode *temp1=first->next; //保存第一个链表的下一个节点
            ListNode *temp2=second->next; //保存第二个链表的下一个节点
            first->next=second; //第一个链表的下一个节点指向第二个链表的当前节点
            second->next=temp1; //第二个链表的下一个节点指向第一个链表的下一个节点
            first=temp1; //第一个链表后移
            second=temp2; //第二个链表后移

        }
        
        

        
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

