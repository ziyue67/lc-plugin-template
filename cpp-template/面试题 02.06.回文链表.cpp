/*
 * @lc app=leetcode.cn id=面试题 02.06 lang=cpp
 * @lcpr version=30305
 *
 * [面试题 02.06] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list-lcci/description/
 *
 * LCCI
 * Easy (49.46%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    75.6K
 * Total Submissions: 152.9K
 * Testcase Example:  '[1,2]\n[]'
 *
 * 编写一个函数，检查输入的链表是否是回文的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： 1->2
 * 输出： false 
 * 
 * 
 * 示例 2：
 * 
 * 输入： 1->2->2->1
 * 输出： true 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        // ListNode*fast=head,*slow=head;//快慢指针找到中间节点
        // while(fast &&fast->next){
        //     fast=fast->next->next;
        //     slow=slow->next;
        // }
        // ListNode *per = nullptr, *cur = slow; // 反转链表 per为头节点1
        // while (cur)
        // {
        //     ListNode *temp=cur->next; // 注意保存下一个节点
        //     cur->next=per;
        //     per=cur;
        //     cur=temp;
        // }
        // while (per &&head) //比较
        // {
        //     if(per->val!=head->val){ // 不是回文链表
        //         return false;
        //     }
        //     per=per->next;
        //     head=head->next; 
        // }
        // return true;
        ListNode *fast = head, *slow = head; // 快慢指针找到中间节点
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 反转后半部分链表
        ListNode *per = nullptr, *cur = slow; // 反转链表 per为头节点1
        while (cur)
        {
            ListNode *temp = cur->next; // 注意保存下一个节点
            cur->next = per;
            per = cur;
            cur = temp;
        }
        // 比较前半部分和反转后的后半部分
        ListNode *left = head;
        ListNode *right = per;
        while (right) // 只需检查right，因为后半部分可能更短
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end

// 辅助函数：从vector创建链表
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

int main() {
    Solution solution;
    cout << boolalpha;
    
    // 测试用例1: [1,2]
    ListNode* head1 = createList({1, 2});
    cout << "测试用例1: " << solution.isPalindrome(head1) << endl;
    
    // 测试用例2: [1,2,2,1]
    ListNode* head2 = createList({1, 2, 2, 1});
    cout << "测试用例2: " << solution.isPalindrome(head2) << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

