/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30305
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (59.32%)
 * Likes:    1574
 * Dislikes: 0
 * Total Accepted:    958.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6\n[]\n1\n[7,7,7,7]\n7'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [], val = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode(0,head); //虚拟头节点
        dummy->next=head; //虚拟头节点指向头节点
        ListNode *q=dummy; //前驱节点
        ListNode *p=head;  //当前节点
        while (p)
        {
            if(p->val==val){
                q->next=p->next;
                delete p;
                p=q->next;
            }
            else
            {
                q=p;
                p=p->next;
            }
            
        }
        ListNode *newHead=dummy->next; //新头节点
        delete dummy; //删除虚拟头节点
        return newHead; //返回新头节点
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

